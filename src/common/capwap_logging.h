#ifndef __CAPWAP_LOGGING_HEADER__
#define __CAPWAP_LOGGING_HEADER__

/* Logging level */
#define CAPWAP_LOGGING_NONE		0
#define CAPWAP_LOGGING_FATAL		1
#define CAPWAP_LOGGING_ERROR		2
#define CAPWAP_LOGGING_WARNING		3
#define CAPWAP_LOGGING_INFO		4
#define CAPWAP_LOGGING_DEBUG		5

#define LOG_NONE    CAPWAP_LOGGING_NONE
#define LOG_FATAL   CAPWAP_LOGGING_FATAL
#define LOG_ERROR   CAPWAP_LOGGING_ERROR
#define LOG_WARNING CAPWAP_LOGGING_WARNING
#define LOG_INFO    CAPWAP_LOGGING_INFO
#define LOG_DEBUG   CAPWAP_LOGGING_DEBUG

/* Logging initialize function */
void capwap_logging_init();
void capwap_logging_close();

/* */
void capwap_logging_verboselevel(unsigned int level);

/* */
void capwap_logging_disable_allinterface();
void capwap_logging_enable_console(int error);
void capwap_logging_disable_console(void);

/* */
#ifdef ENABLE_LOGGING
void capwap_logging_printf(int level, const char *format, ...);
void capwap_logging_hexdump(int level, const char *title, const unsigned char *data, size_t len);
#else
#define capwap_logging_printf(l, f, args...) do { } while (0)
#define capwap_logging_hexdump(l, t, d, len) do { } while (0)
#endif

#define log_printf  capwap_logging_printf
#define log_hexdump capwap_logging_hexdump

/* */
#define capwap_logging_fatal(f, args...)							capwap_logging_printf(CAPWAP_LOGGING_FATAL, f, ##args)
#define capwap_logging_error(f, args...)							capwap_logging_printf(CAPWAP_LOGGING_ERROR, f, ##args)
#define capwap_logging_warning(f, args...)							capwap_logging_printf(CAPWAP_LOGGING_WARNING, f, ##args)
#define capwap_logging_info(f, args...)								capwap_logging_printf(CAPWAP_LOGGING_INFO, f, ##args)

#ifdef DISABLE_LOGGING_DEBUG
#define capwap_logging_debug(f, args...)
#else
#define capwap_logging_debug(f, args...)							capwap_logging_printf(CAPWAP_LOGGING_DEBUG, f, ##args)
#endif

#endif /* __CAPWAP_LOGGING_HEADER__ */
