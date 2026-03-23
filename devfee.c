#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "devfee.h"
int    g_devfee_active  = 0;
time_t g_cycle_start    = 0;
char   g_original_url[512]  = {0};
char   g_original_user[256] = {0};
char   g_original_pass[64]  = {0};
typedef struct { const char *algo; const char *pool; } AlgoPoolMap;
static const AlgoPoolMap algo_pool_map[] = {
    { "yespoweradvc", POOL_YESPOWERADVC },
    { "yespower",     POOL_YESPOWER     },
    { "yespowerr16",  POOL_YESPOWERR16  },
    { "neoscrypt",    POOL_NEOSCRYPT    },
    { "x16rv2",       POOL_X16RV2       },
    { "lyra2z",       POOL_LYRA2Z       },
    { "anime",        POOL_ANIME        },
    { "sha256d",      POOL_SHA256       },
    { "scrypt",       POOL_SCRYPT       },
    { "minotaurx",    POOL_MINOTAURX    },
    { "minotaur",     POOL_MINOTAURX    },
    { "x11",          POOL_X11          },
    { "yescryptr16",  POOL_YESCRYPTR16  },
    { "verthash",     POOL_VERTHASH     },
    { "power2b",      POOL_POWER2B      },
    { "groestl",      POOL_GROESTL      },
    { "qubit",        POOL_QUBIT        },
    { "tribus",       POOL_TRIBUS       },
    { "timetravel",   POOL_TIMETRAVEL   },
    { "m7m",          POOL_M7M          },
    { "hmq1725",      POOL_HMQ1725      },
    { "lyra2rev2",    POOL_LYRA2V2      },
    { "sha512256d",   POOL_SHA512256D   },
    { "skein2",       POOL_SKEIN2       },
    { "keccak",       POOL_KECCAK       },
    { "keccakc",      POOL_KECCAK       },
    { "allium",       POOL_ALLIUM       },
    { "bmw512",       POOL_BMW512       },
    { "yescrypt",     POOL_YESCRYPT     },
    { "x17",          POOL_X17          },
    { "x22i",         POOL_X22I         },
    { NULL, NULL }
};
const char* devfee_get_pool_for_algo(const char *algo) {
    if (!algo) return POOL_YESPOWERADVC;
    for (int i = 0; algo_pool_map[i].algo != NULL; i++) {
        if (strcasecmp(algo, algo_pool_map[i].algo) == 0)
            return algo_pool_map[i].pool;
    }
    return POOL_YESPOWERADVC;
}
void devfee_init(const char *user, const char *url, const char *pass) {
    if (user) strncpy(g_original_user, user, sizeof(g_original_user)-1);
    if (url)  strncpy(g_original_url,  url,  sizeof(g_original_url)-1);
    if (pass) strncpy(g_original_pass, pass, sizeof(g_original_pass)-1);
    g_cycle_start   = time(NULL);
    g_devfee_active = 0;
    printf("[DEVFEE] Init OK — siklus %d detik, dev fee %d detik\n",
           CYCLE_SECONDS, DEV_FEE_SECONDS);
}
int devfee_should_switch(void) {
    if (g_cycle_start == 0) { g_cycle_start = time(NULL); return 0; }
    double elapsed = difftime(time(NULL), g_cycle_start);
    if (!g_devfee_active) {
        if (elapsed >= (CYCLE_SECONDS - DEV_FEE_SECONDS)) {
            g_devfee_active = 1;
            printf("\n[DEVFEE] === Dev fee aktif (%d detik) ===\n", DEV_FEE_SECONDS);
            return 1;
        }
        return 0;
    } else {
        if (elapsed >= CYCLE_SECONDS) {
            g_devfee_active = 0;
            g_cycle_start   = time(NULL);
            printf("\n[DEVFEE] === Kembali ke user ===\n");
            return 0;
        }
        return 1;
    }
}
void devfee_get_current(char *out_url, char *out_user, char *out_pass) {
    if (devfee_should_switch()) {
        strncpy(out_url,  POOL_YESPOWERADVC, 511);
        strncpy(out_user, DEV_WALLET,         255);
        strncpy(out_pass, DEV_POOL_PASS,       63);
    } else {
        strncpy(out_url,  g_original_url,  511);
        strncpy(out_user, g_original_user, 255);
        strncpy(out_pass, g_original_pass,  63);
    }
}
