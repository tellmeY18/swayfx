#define _POSIX_C_SOURCE 200809L
#include "sway/commands.h"
#include "sway/config.h"
#include "util.h"

struct cmd_results *cmd_ws_gesture_spring_size(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "workspace_gesture_spring_size", EXPECTED_EQUAL_TO, 1))) {
		return error;
	}

	char *inv;
	int value = strtol(argv[0], &inv, 10);
	if (*inv != '\0' || value < 0 || value > 250) {
		return cmd_results_new(CMD_FAILURE, "Invalid size specified");
	}

	config->workspace_gesture_spring_size = value;

	return cmd_results_new(CMD_SUCCESS, NULL);
}

struct cmd_results *cmd_ws_gesture_wrap_around(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "workspace_gesture_wrap_around", EXPECTED_EQUAL_TO, 1))) {
		return error;
	}

	config->workspace_gesture_wrap_around = parse_boolean(argv[0], true);

	return cmd_results_new(CMD_SUCCESS, NULL);
}
