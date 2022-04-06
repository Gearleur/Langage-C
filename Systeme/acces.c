#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>

int main(int argn, char *argv[])
{
    struct stat buf;
    struct passwd *usrbuf;
    struct group *grbuf;
    DIR *dossier;
    struct dirent *couple;
    if (argn != 2)
    {
        fprintf(stderr, "my_ls: un argument requis\n");
        exit(1);
    }
    if ((dossier = opendir(argv[1])) == NULL)
    {
        perror("my_ls:opendir");
        exit(2);
    }
    chdir(argv[1]);
    while ((couple = readdir(dossier)) != NULL)
    {
        stat(couple->d_name, &buf);
        printf("Fichier: %s\n", couple->d_name);
        printf("i-noeud: %d\n", (int)buf.st_ino);
        printf("Nbr liens : %d\n", buf.st_nlink);
        if ((usrbuf = getpwuid(buf.st_uid)) == NULL)
        {
            perror("my_ls: getpwuid");
            exit(4);
        }
        printf("Proprio : %d (%s)\n", buf.st_uid,
        usrbuf->pw_name);
        if ((grbuf = getgrgid(buf.st_gid)) == NULL)
        {
            perror("my_ls: getgrgid");
            exit(5);
        }
            printf("Groupe : %d (%s)\n", buf.st_gid,
            grbuf->gr_name);
            printf("Taille : %d\n", (int)buf.st_size);
            printf("Derniere modif du i-noeud: %s", ctime(&buf.st_ctime));
            printf("Derniere modif du fichier: %s", ctime(&buf.st_mtime));
            printf("Dernier acces : %s\n", ctime(&buf.st_atime));
        }
    closedir(dossier);
    exit(0);
}