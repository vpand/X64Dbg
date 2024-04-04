def gen_reg_property_impl(regname):
    print('''
    def __get_%s_property__(self):
        return register_proc('%s')
    def __set_%s_property__(self, value):
        return register_proc('%s', value)
    %s = property(__get_%s_property__, __set_%s_property__)''' % (
        regname, regname, regname, regname, 
        regname, regname, regname))

def gen_reg_property(name, count):
    for i in range(0, count):
        regname = '%s%d' % (name, i)
        gen_reg_property_impl(regname)

def gen_reg_proptery_names(prefix, names):
    for n in names:
        gen_reg_property_impl(prefix + n)

def gen_reg_wrapper_impl(prefix, regname):
    print('%s = %s%s' % (regname, prefix, regname))

def gen_reg_wrapper(prefix, name, count):
    for i in range(0, count):
        regname = '%s%d' % (name, i)
        gen_reg_wrapper_impl(prefix, regname)

def gen_adpdef():
    with open('adpdef.hpp', 'r') as fp:
        outsrc = ''
        erridx = 0
        eventidx = 0
        while True:
            line = fp.readline()
            if len(line) == 0 or line.startswith('enum adp_platform_t'):
                break
            if line.startswith('};'):
                outsrc += "\n"
            if line.startswith('#define __ADP_VERSION__ '):
                outsrc += "adp_version = '%s'\n\n" % (line.split('"')[1])
                continue
            if line.startswith('  adp_err_'):
                outsrc += "%s = %d # %s" % (line.split(',')[0].split(' ')[2], erridx, line.split(' // ')[1])
                erridx += 1
                continue
            if line.startswith('  decl_event'):
                outsrc += "adp_event_%s = %d # %s\n" % (line.split('(')[1].split(',')[0], eventidx, line.split('"')[1])
                eventidx += 1
                continue
        with open('adpdef.py', 'w') as fp:
            fp.write(
'''##################################YUNYOO.CN####################################
#                                                                             *
# AUTO GENERTATED A64Dbg PLUGIN PYTHON INTERFACE FILE                         *
#                                                                             *
# Copyright(C) 2021 YunYoo Corp., ALL RIGHTS RESERVED.                        *
#                                                                             *
# Internet: yunyoo.cn                                                         *
#                                                                             *
# This code is distributed "as is", part of A64Dbg and without warranty of    *
# any kind, expressed or implied, including, but not limited to warranty of   *
# fitness for any particular purpose. In no event will A64Dbg be liable to    *
# you for any special, incidental, indirect, consequential or any other       *
# damages caused by the use, misuse, or the inability to use of this code,    *
# including anylost profits or lost savings, even if A64Dbg has been advised  *
# of the possibility of such damages.                                         *
#                                                                             *
######################################*#######################################/

# keys for adp_on_event args
adp_inkey_name = 'name' # plugin module name
adp_inkey_type = 'event' # event type
adp_inkey_value = 'value' # event payload
adp_outkey_error = 'error' # return error code
adp_outkey_result = 'result' # return value

adp_local_mac = 0 # Local macOS/Simulator
adp_remote_ios = 1 # Remote iOS
adp_remote_android = 2 # Remote Android
adp_local_vp_ios = 3 # Local VP iOS Simulator
adp_remote_vp_android = 4 # Remote VP Android Emulator
adp_local_uraniumvm = 5 # Local UraniumVM
adp_remote_uraniumvm_ios = 6 # Remote UraniumVM iOS
adp_remote_uraniumvm_android = 7 # Remote UraniumVM Android
adp_invalid_platform = 8

adp_arch_unsupport = 0
adp_arch_armv5te = 1
adp_arch_arm = 2
adp_arch_arm64 = 3
adp_arch_x86 = 4
adp_arch_x64 = 5

%s''' % (outsrc))

if 0:
    gen_reg_proptery_names('_', [
        'c', 'p', 'a', 'z', 's', 't', 'i', 'd', 'o'
    ])

if 0:
    gen_reg_proptery_names('e', [
        'ax', 'cx', 'dx', 'bx', 'bp', 'si', 'di',
    ])
    gen_reg_proptery_names('r', [
        'ax', 'cx', 'dx', 'bx', 'bp', 'si', 'di',
    ])

gen_adpdef()
