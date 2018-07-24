
#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <ftw.h>

static int display_info(const char* path,const struct stat* sb,int flag,struct FTW* ftw);
int main() {
    printf("Hello, World!\n");
    nftw(".",display_info,20,FTW_DEPTH);
    return 0;
}

static int display_info(const char* path,const struct stat* sb,int flag,struct FTW* ftw){
    printf("%-3s %2d",
                (flag==FTW_D)?"d"
               :(flag==FTW_DNR)?"dnr"
               :(flag==FTW_DP)?"dp"
               :(flag==FTW_F)?"f"
               :(flag==FTW_NS)?"ns"
               :(flag==FTW_SL)?"sl"
               :(flag==FTW_SLN)?"sld":"???",ftw->level);

    if(flag==FTW_NS){
        printf("---");
    }else {
        printf("%7jd", sb->st_size);
    }

    printf("%80s| %2d |%s\n",path,ftw->base,path+ftw->base);
    return 0;
}