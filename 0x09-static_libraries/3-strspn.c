#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

unsigned int_strspn(char *s, char *accept)
{
	return strspn(s,accept);
}
