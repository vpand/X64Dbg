#ifndef A64DBG_H
#define A64DBG_H

#define A64DBG_VERSION "1.17.0"
#define A64DBG_RELEASE 1

// release
#if A64DBG_RELEASE
#define A64DBG_BUILD_INFO ""
#else
// preview
#define A64DBG_BUILD_INFO " [SP %3]"
#endif

#include "../A64Dbg/include/adpdef.hpp"

#include <QString>
#include <vector>

#define CFGSECT_ADP "ADPlugin"

// textobot httpsvr port
#define TB_HTTP_PORT "30330"

typedef adp_error_t (*adp_main_t)(adp_payload_t *adp);

struct ADPluginInstance {
  QString path;
  adp_main_t entry;
  adp_payload_t *payload;
  void *module;
  bool enable;

  bool isPython() {
    return entry == nullptr;
  }

  void resetPayload() {
    memset(&payload->input, 0, sizeof(payload->input));
    memset(&payload->result, 0, sizeof(payload->result));
  }

  adp_error_t invoke(adp_event_t event) {
    resetPayload();
    payload->event = event;
    return callEntry();
  }

  void invoke(adp_event_t event, void *ptr) {
    resetPayload();
    payload->event = event;
    payload->input.ptr = ptr;
    callEntry();
  }

  void invoke(adp_event_t event, adp_input_t *input) {
    resetPayload();
    payload->event = event;
    payload->input = *input;
    callEntry();
  }

  std::string invokeConstString(adp_event_t event) {
    if (invoke(event) != adp_err_ok) {
      return "";
    }
    if (isPython()) {
      std::string result = payload->result.str_dyn;
      free(payload->result.str_dyn);
      return result;
    }
    return payload->result.str_const;
  }

  std::string version() { return invokeConstString(adp_event_version); }

  std::string info(std::string *desc) {
    if (invoke(adp_event_adpinfo) != adp_err_ok) {
      *desc = "";
      return "";
    }
    *desc = (char *)payload->result.ptr.p1;
    if (isPython()) {
      std::string result = (char *)payload->result.ptr.p0;
      free(payload->result.ptr.p0);
      free(payload->result.ptr.p1);
      return result;
    }
    return (char *)payload->result.ptr.p0;
  }

  std::string name() { return invokeConstString(adp_event_menuname); }

 private:
  bool shouldCall() {
    switch (payload->event) {
      case adp_event_loaded:
      case adp_event_pre_unload:
      case adp_event_version:
      case adp_event_adpinfo:
      case adp_event_menuname:
        return true;
      default:
        return false;
    }
  }

  adp_error_t callEntry();
};

class ADPluginManager {
 public:
  static ADPluginManager *inst() {
    static ADPluginManager mgr;
    return &mgr;
  }

  int loadADP();
  void unloadADP();

  void sendEvent(adp_event_t event);
  void sendEvent(adp_event_t event, void *ptr);
  void sendEvent(adp_event_t event, adp_input_t *input);

  std::vector<ADPluginInstance> adps;
  int (*adp_eval)(const char *expr, char *outbuff, int outsz);
  bool (*adp_expr_valid)(const char *expr);
  adp_error_t (*adp_main_py)(const char *pymod, adp_payload_t *adp);

 protected:
  ADPluginManager() {}
  ~ADPluginManager() {}

  void loadADP(const QString &dir);
  void loadADPPython(const QString &dir);

  adp_api_t api;
  adp_payload_t payload;
};

#endif  // end of A64DBG_H
