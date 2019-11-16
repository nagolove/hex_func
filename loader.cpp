#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/mman.h>

typedef int (*Func)(int, int);

int main(int argc, char *argv[])
{
    int dataSize;
    FILE* fp = fopen("source.b", "rb");
    fseek(fp, 0, SEEK_END);
    dataSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    printf("data size %d\n", dataSize);
    char* binCode = (char*)malloc(dataSize);
    fread(binCode, dataSize, 1, fp);
    fclose(fp);
    void* mem = mmap(NULL, dataSize, PROT_WRITE | PROT_EXEC | MAP_ANON |
        MAP_PRIVATE, -1, 0, 0);
    memcpy(mem, binCode, dataSize);
    //int (*codeFunc)(int, int) = mem;
    Func codeFunc = (Func)mem;
    int arg1 = 1, arg2 = 1;
    printf("Run with (%d, %d) result is %d", arg1, arg2, codeFunc(arg1, arg2));
    free(binCode);
    munmap(mem, dataSize);
    return 0;
}
