// messages/default.h -- default fcheck error messages
// to make program use it, rename file to current.h

#define FC_MESSAGE_H

#define FC_PREFIX 		"\n"
#define FC_FAILED_TO_OPEN 	"Could not open the file \"" << filename << "\".\n"
#define FC_EOF 			"End of file \"" << filename << "\" reached.\n"
#define FC_FAIL			"Input from file \"" << filename << "\" terminated by data missmatch.\n"
#define FC_BAD			"Input from file \"" << filename << "\" terminated for unknown reason.\n"
#define FC_EOF_MSG		"End of file \"" << filename << "\" reached.\n"

// reference: 
// 		'filename' -- pointer to char array or char array passed to function
