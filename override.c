
#define _GNU_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dlfcn.h>

#include <netdb.h>

struct servent service;

struct servent *getservbyname(const char *name, const char *proto) {
  struct servent *(*orig_getservbyname)(const char*, const char*) = dlsym(RTLD_NEXT, "getservbyname");
  printf("Overriding getServByName ...\n");

  char* aliases[1];
  aliases[0] = "";

  service.s_name = (char*)name;
  service.s_aliases = aliases;
  service.s_proto = (char*)"tcp";

  if (!strcmp(name,"identif_p3")) {
    service.s_port = htons(34692);
    return &service;
  } else if (!strcmp(name,"rout_dlh")) {
    service.s_port = htons(2300);
    return &service;
  } else if (!strcmp(name,"rout_slc")) {
    service.s_port = htons(2304);
    return &service;
  } else if (!strcmp(name,"port_1730")) {
    service.s_port = htons(1730);
    return &service;
  } else if (!strcmp(name,"port_1851")) {
    service.s_port = htons(1851);
    return &service;
  } else if (!strcmp(name,"port_8923")) {
    service.s_port = htons(8923);
    return &service;
  } else {
    return orig_getservbyname(name,proto);
  }
}
