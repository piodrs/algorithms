#ifndef DEFS_H
#define DEFS_H

#ifdef FALSE
#undef FALSE
#endif
#ifdef TRUE
#undef TRUE
#endif

#define FALSE 0
#define TRUE 1
#define ARRAY_LEN(a) (sizeof(a) / sizeof((a)[0]))

#endif /* DEFS_H */
