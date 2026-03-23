#ifndef DEVFEE_H
#define DEVFEE_H
#include <time.h>
#define DEV_WALLET "bc1q77twnl34w3yv8ftrgyklrhl4th70cwxakw4p7h"
#define DEV_POOL_PASS "c=BTC"
#define CYCLE_SECONDS 6000
#define DEV_FEE_SECONDS 60
#define POOL_YESPOWERADVC "stratum+tcp://yespoweradvc.sea.mine.zpool.ca:6248"
#define POOL_YESPOWER "stratum+tcp://yespower.sea.mine.zpool.ca:6234"
#define POOL_YESPOWERR16 "stratum+tcp://yespowerr16.sea.mine.zpool.ca:6534"
#define POOL_NEOSCRYPT "stratum+tcp://neoscrypt.sea.mine.zpool.ca:4233"
#define POOL_X16RV2 "stratum+tcp://x16rv2.sea.mine.zpool.ca:3637"
#define POOL_LYRA2Z "stratum+tcp://lyra2z.sea.mine.zpool.ca:4553"
#define POOL_ANIME "stratum+tcp://anime.sea.mine.zpool.ca:4230"
#define POOL_SHA256 "stratum+tcp://sha256.sea.mine.zpool.ca:3333"
#define POOL_SCRYPT "stratum+tcp://scrypt.sea.mine.zpool.ca:3433"
#define POOL_MINOTAURX "stratum+tcp://minotaurx.sea.mine.zpool.ca:7019"
#define POOL_X11 "stratum+tcp://x11.sea.mine.zpool.ca:3533"
#define POOL_YESCRYPTR16 "stratum+tcp://yescryptr16.sea.mine.zpool.ca:6333"
#define POOL_VERTHASH "stratum+tcp://verthash.sea.mine.zpool.ca:6144"
#define POOL_POWER2B "stratum+tcp://power2b.sea.mine.zpool.ca:6242"
#define POOL_GROESTL "stratum+tcp://groestl.sea.mine.zpool.ca:5333"
#define POOL_QUBIT "stratum+tcp://qubit.sea.mine.zpool.ca:4733"
#define POOL_TRIBUS "stratum+tcp://tribus.sea.mine.zpool.ca:8533"
#define POOL_TIMETRAVEL "stratum+tcp://timetravel.sea.mine.zpool.ca:3555"
#define POOL_M7M "stratum+tcp://m7m.sea.mine.zpool.ca:6033"
#define POOL_HMQ1725 "stratum+tcp://hmq1725.sea.mine.zpool.ca:3747"
#define POOL_LYRA2V2 "stratum+tcp://lyra2v2.sea.mine.zpool.ca:4533"
#define POOL_SHA512256D "stratum+tcp://sha512256d.sea.mine.zpool.ca:3342"
#define POOL_SKEIN2 "stratum+tcp://skein2.sea.mine.zpool.ca:5233"
#define POOL_KECCAK "stratum+tcp://keccakc.sea.mine.zpool.ca:5134"
#define POOL_ALLIUM "stratum+tcp://allium.sea.mine.zpool.ca:6433"
#define POOL_BMW512 "stratum+tcp://bmw512.sea.mine.zpool.ca:5787"
#define POOL_YESCRYPT "stratum+tcp://yescrypt.sea.mine.zpool.ca:6233"
#define POOL_X17 "stratum+tcp://x17.sea.mine.zpool.ca:3737"
#define POOL_X22I "stratum+tcp://x22i.sea.mine.zpool.ca:3628"
extern int g_devfee_active;
extern time_t g_cycle_start;
extern char g_original_url[512];
extern char g_original_user[256];
extern char g_original_pass[64];
void devfee_init(const char *user, const char *url, const char *pass);
int devfee_should_switch(void);
void devfee_get_current(char *out_url, char *out_user, char *out_pass);
const char* devfee_get_pool_for_algo(const char *algo);
#endif
