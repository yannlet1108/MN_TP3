#include <stdlib.h>

#include "graphe.h"
#include "file.h"

pfile_t creer_file()
{
  pfile_t f = (pfile_t)malloc(sizeof(file_t));
  if (f == NULL)
    return NULL;

  f->tete = 0;
  f->queue = -1;
  return f;
}

int detruire_file(pfile_t f)
{
  free(f);
  return 0;
}

int file_vide(pfile_t f)
{
  return f->tete > f->queue;
}

int file_pleine(pfile_t f)
{
  return (f->queue == MAX_FILE_SIZE - 1) && (f->tete == 0);
}

psommet_t defiler(pfile_t f)
{
  if (file_vide(f))
    return NULL;

  psommet_t p = f->Tab[f->tete];
  f->tete++;
  return p;
}

int enfiler(pfile_t f, psommet_t p)
{
  if (file_pleine(f))
    return -1;

  if (f->queue == MAX_FILE_SIZE - 1)
  {
    for (int i = f->tete; i <= f->queue; i++)
      f->Tab[i - f->tete] = f->Tab[i];
    f->tete = 0;
    f->queue = f->queue - f->tete;
  }

  f->queue++;
  f->Tab[f->queue] = p;
  return 0;
}
