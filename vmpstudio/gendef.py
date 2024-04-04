def gen_vspdef():
    with open('vspdef.hpp', 'r') as fp:
        outsrc = ''
        erridx = 0
        eventidx = 0
        while True:
            line = fp.readline()
            if len(line) == 0 or line.startswith('enum vsp_file_t'):
                break
            if line.startswith('};'):
                outsrc += "\n"
            if line.startswith('#define __VSP_VERSION__ '):
                outsrc += "vsp_version = '%s'\n\n" % (line.split('"')[1])
                continue
            if line.startswith('  vsp_err_'):
                outsrc += "%s = %d # %s" % (line.split(',')[0].split(' ')[2], erridx, line.split(' // ')[1])
                erridx += 1
                continue
            if line.startswith('  decl_event'):
                outsrc += "vsp_event_%s = %d # %s\n" % (line.split('(')[1].split(',')[0], eventidx, line.split('"')[1])
                eventidx += 1
                continue
        with open('vspdef.py', 'w') as fp:
            fp.write(
'''##################################YUNYOO.CN####################################
#                                                                             *
# AUTO GENERTATED VMPStudio PLUGIN PYTHON INTERFACE FILE                      *
#                                                                             *
# Copyright(C) 2022 YunYoo Corp., ALL RIGHTS RESERVED.                        *
#                                                                             *
# Internet: yunyoo.cn                                                         *
#                                                                             *
# This code is distributed "as is", part of VMPStudio and without warranty of *
# any kind, expressed or implied, including, but not limited to warranty of   *
# fitness for any particular purpose. In no event will VMPStudio be liable to *
# you for any special, incidental, indirect, consequential or any other       *
# damages caused by the use, misuse, or the inability to use of this code,    *
# including anylost profits or lost savings,even if VMPStudio has been advised*
# of the possibility of such damages.                                         *
#                                                                             *
######################################*#######################################/

# keys for vsp_on_event args
vsp_inkey_name = 'name' # plugin module name
vsp_inkey_type = 'event' # event type
vsp_inkey_value = 'value' # event payload
vsp_outkey_error = 'error' # return error code
vsp_outkey_result = 'result' # return value

vsp_arch_unsupport = 0
vsp_arch_armv5te = 1
vsp_arch_arm = 2
vsp_arch_arm64 = 3
vsp_arch_x86 = 4
vsp_arch_x64 = 5

%s''' % (outsrc))

gen_vspdef()
