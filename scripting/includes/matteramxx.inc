#define TARGET_URL_LENGTH 1024
#define MESSAGE_LENGTH 512
#define BASE_URL_LENGTH 256
#define JSON_PARAMETER_LENGTH 256
#define TOKEN_LENGTH 64

#if AMXX_VERSION_NUM < 183
    #define MAX_PLAYERS 32
    #define MAX_NAME_LENGTH 32
#endif

#pragma reqlib "matteramxx"

#if !defined AMXMODX_NOAUTOLOAD
   #pragma loadlib "matteramxx"
#endif

enum {
  MATTER_IGNORE = 0,
  MATTER_SUPERCEDE,
};

/**
 * Called when we get a message coming from Matterbridge
 * 
 * This forward has 2 possible return values:
 * · MATTER_IGNORE ignores the forward and posts the message as it is.
 * · MATTER_SUPERCEDE prevents the message from sending.
 *
 * @param	    message[] - Message coming from Matterbridge.
 *
 */
forward matteramxx_print_message(message[MESSAGE_LENGTH], username[MAX_NAME_LENGTH], protocol[MAX_NAME_LENGTH], userid[MAX_NAME_LENGTH]);

/**
 * Method to send a message to the configured Matterbridge instance.
 *
 * @param		message[] - Message you want to send
 * @param		username[] - Username that will appear in the protocols
 * @param		avatar[] - URL pointing to the avatar of this "user" (On protocols that support it)
 * @param		is_system - If true, message won't be printed in other game servers
 * @param		gateway[] - Specify the gateway we should send this message, main if empty
 *
 */
native matteramxx_send_message(const message[], const username[] = "", const avatar[] = "", const bool:is_system = false, const gateway[] = "");