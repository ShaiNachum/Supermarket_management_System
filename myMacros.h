#pragma once

	#define CHECK_RETRUN_0(pointer)								if(!pointer){ return 0;}

#define CHECK_RETURN_NULL(str)									if(!str){ return NULL;}

#define CHECK_MSG_RETURN_NULL(ptr, msg)							if(!ptr){ puts(msg); return NULL;}

#define CHECK_NULL_MSG_FREE_CLOSE_FILE_RETURN_0(ptr, pName, fp)	if(!ptr){ printf("Allocation error\n"); free(pName); fclose(fp); return 0;}

#define CHECK_NULL_CLOSE_FILE_RETURN_0(ptr, fp)					if(!ptr){ fclose(fp); return 0;}