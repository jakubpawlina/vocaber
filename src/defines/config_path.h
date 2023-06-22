#ifndef VOCABER_CONFIG_PATH_H
#define VOCABER_CONFIG_PATH_H

/*
 * Defines path to config files (icon, logo etc.).
 *
 * For DEBUG files from the repository are used.
 * Currently only LINUX uses release-type path.
 */

#ifndef CONFIG_PATH
#ifdef DEBUG
    #define CONFIG_PATH "../install/config/"
#elif _WIN32
    #define CONFIG_PATH "../install/config/"
#elif __APPLE__
    #define CONFIG_PATH "../install/config/"
#elif __linux__
    #define CONFIG_PATH "/usr/local/share/vocaber/config/"
#else
    #define CONFIG_PATH "../install/config/"
#endif
#endif //CONFIG_PATH

#endif //VOCABER_CONFIG_PATH_H
