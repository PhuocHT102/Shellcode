#include <windows.h>
#include <stdio.h>

unsigned char MsgBox_shellcode[] = {
    0x55, 0x8B, 0xEC, 0x81, 0xEC, 0x00, 0x01, 0x00, 0x00, 0x64, 0xA1, 0x30, 0x00, 0x00, 0x00, 0x8B,
    0x40, 0x0C, 0x8B, 0x40, 0x14, 0x8B, 0x00, 0x8B, 0x00, 0x8B, 0x00, 0x8B, 0x40, 0x10, 0x89, 0x45,
    0xFC, 0x6A, 0x00, 0x68, 0x73, 0x73, 0x61, 0x61, 0x66, 0x81, 0x6C, 0x24, 0x02, 0x61, 0x61, 0x68,
    0x64, 0x64, 0x72, 0x65, 0x68, 0x72, 0x6F, 0x63, 0x41, 0x68, 0x47, 0x65, 0x74, 0x50, 0x89, 0x65,
    0xD8, 0x8B, 0xD8, 0x8B, 0x43, 0x3C, 0x03, 0xC3, 0x8B, 0x40, 0x78, 0x03, 0xC3, 0x8B, 0x48, 0x14,
    0x89, 0x4D, 0xE8, 0x8B, 0x48, 0x1C, 0x03, 0xCB, 0x89, 0x4D, 0xE4, 0x8B, 0x48, 0x20, 0x03, 0xCB,
    0x89, 0x4D, 0xE0, 0x8B, 0x48, 0x24, 0x03, 0xCB, 0x89, 0x4D, 0xDC, 0x33, 0xC0, 0x33, 0xC9, 0x8B,
    0x75, 0xD8, 0x8B, 0x7D, 0xE0, 0xFC, 0x8B, 0x3C, 0x87, 0x03, 0xFB, 0x66, 0xB9, 0x08, 0x00, 0xF3,
    0xA6, 0x74, 0x06, 0x40, 0x3B, 0x45, 0xE8, 0x75, 0xE6, 0x8B, 0x4D, 0xDC, 0x8B, 0x55, 0xE4, 0x66,
    0x8B, 0x04, 0x41, 0x8B, 0x04, 0x82, 0x03, 0xC3, 0x89, 0x45, 0xF8, 0x6A, 0x00, 0x68, 0x61, 0x72,
    0x79, 0x41, 0x68, 0x4C, 0x69, 0x62, 0x72, 0x68, 0x4C, 0x6F, 0x61, 0x64, 0x54, 0xFF, 0x75, 0xFC,
    0xFF, 0x55, 0xF8, 0x89, 0x45, 0xF4, 0x6A, 0x00, 0x68, 0x6C, 0x6C, 0x61, 0x61, 0x66, 0x81, 0x6C,
    0x24, 0x02, 0x61, 0x61, 0x68, 0x33, 0x32, 0x2E, 0x64, 0x68, 0x75, 0x73, 0x65, 0x72, 0x54, 0xFF,
    0x55, 0xF4, 0x89, 0x45, 0xF0, 0x6A, 0x00, 0x68, 0x6F, 0x78, 0x41, 0x61, 0x80, 0x6C, 0x24, 0x03,
    0x61, 0x68, 0x61, 0x67, 0x65, 0x42, 0x68, 0x4D, 0x65, 0x73, 0x73, 0x54, 0xFF, 0x75, 0xF0, 0xFF,
    0x55, 0xF8, 0x89, 0x45, 0xEC, 0x6A, 0x00, 0x68, 0x74, 0x21, 0x61, 0x61, 0x66, 0x81, 0x6C, 0x24,
    0x02, 0x61, 0x61, 0x68, 0x20, 0x63, 0x68, 0x61, 0x68, 0x20, 0x63, 0x75, 0x63, 0x68, 0x65, 0x62,
    0x6F, 0x78, 0x68, 0x73, 0x73, 0x61, 0x67, 0x68, 0x65, 0x20, 0x6D, 0x65, 0x68, 0x6C, 0x63, 0x6F,
    0x64, 0x68, 0x73, 0x68, 0x65, 0x6C, 0x8B, 0xC4, 0x6A, 0x00, 0x68, 0x20, 0x64, 0x65, 0x21, 0x68,
    0x20, 0x68, 0x6F, 0x69, 0x68, 0x20, 0x6E, 0x61, 0x79, 0x68, 0x67, 0x61, 0x6D, 0x65, 0x8B, 0xDC,
    0x6A, 0x00, 0x50, 0x53, 0x6A, 0x00, 0xFF, 0x55, 0xEC, 0x6A, 0x00, 0x68, 0x65, 0x73, 0x73, 0x61,
    0x66, 0x83, 0x6C, 0x24, 0x03, 0x61, 0x68, 0x50, 0x72, 0x6F, 0x63, 0x68, 0x45, 0x78, 0x69, 0x74,
    0x54, 0xFF, 0x75, 0xFC, 0xFF, 0x55, 0xF8, 0x6A, 0x00, 0xFF, 0xD0
}; 

int main() {
    char* alloc_mem = (char*)VirtualAlloc(NULL, sizeof(MsgBox_shellcode), (MEM_COMMIT | MEM_RESERVE), PAGE_EXECUTE_READWRITE);

    for (int i = 0; i < sizeof(MsgBox_shellcode); i++) {
        alloc_mem[i] = MsgBox_shellcode[i];
    }

    ((void(*)())alloc_mem)();

    VirtualFree(alloc_mem, sizeof(MsgBox_shellcode), MEM_RELEASE);

    return 0;
}
