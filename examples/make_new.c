#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <libgrf.h>

int main(int argc, char *argv[]) {
  int fp;
  void *grf, *new_node;
  char *ptr;
  struct stat f;
  grf = grf_new("file.grf", true); /* open in write mode */
  fp  = open("make_new.c", O_RDONLY);
  if (fp < 0) {
    perror("open");
    return 1;
  }
  fstat(fp, (struct stat *)&f);
  ptr = (char *)malloc(f.st_size);
  if (read(fp, ptr, f.st_size) != f.st_size) {
    perror("read");
    free(ptr);
    return 2;
  }
  new_node = grf_file_add(grf, "data\\test.txt", ptr, f.st_size);
  free(ptr);
  if (new_node == NULL) {
    printf("Impossible d'ajouter le fichier\n");
    return 3;
  }
  printf("Fichier ajout� � l'adresse %p\n", new_node);
  grf_free(grf); /* should call grf_save(), as the grf was modified */
  return 0;
}
