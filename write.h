#ifndef E2TOOLS_WRITE_H
#define E2TOOLS_WRITE_H

/* from write.c */
extern long
put_file(ext2_filsys fs, ext2_ino_t cwd, char *infile, char *outfile,
         ext2_ino_t *outfile_ino, int keep, struct stat *def_stat);

#endif /* !E2TOOLS_WRITE_H */
