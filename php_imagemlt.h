/* imagemlt extension for PHP */

#ifndef PHP_IMAGEMLT_H
# define PHP_IMAGEMLT_H

extern zend_module_entry imagemlt_module_entry;
# define phpext_imagemlt_ptr &imagemlt_module_entry

# define PHP_IMAGEMLT_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_IMAGEMLT)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#define ZEND_OPCODE_HANDLER_ARGS void


#endif	/* PHP_IMAGEMLT_H */

