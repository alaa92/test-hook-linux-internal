#include "../Memory/mem/mem.hpp"
const mem::uintptr_t offset = 0x12d0;
typedef int(* test_t)(int num1, int num2);
mem::int_t hk_size = 9;
test_t o_test;
int hk_test(int num1, int num2)
{
    num1 = 1000;
    num2 =  337;
    return o_test(num1, num2);
}

__attribute__((constructor))
void libmain()
{
    system("zenity --info --title=\"test_hook\" --text=\"injected\"");
    mem::moduleinfo_t target = mem::in::get_module_info("/target\n");
    std::stringstream ss;
    ss << "zenity --info --title=\"test_hook\" --text=\"" << 
        "target name: " << target.name << "\n" <<
        "target path: " << target.path << "\n" <<
        "target base: " << target.base << "\n" <<
        "target size: " << target.size << "\n" <<
        "target end: "  << target.end  << "\n" << "\"";
    
    //system(ss.str().c_str());
    mem::voidptr_t test_addr = (mem::voidptr_t)((mem::uintptr_t)target.base + offset);
    o_test = (test_t)mem::in::detour_trampoline(test_addr, (mem::voidptr_t)&hk_test, hk_size);
}