--TEST--
imagemlt_test1() Basic test
--SKIPIF--
<?php
if (!extension_loaded('imagemlt')) {
	echo 'skip';
}
?>
--FILE--
<?php
$ret = imagemlt_test1();

var_dump($ret);
?>
--EXPECT--
The extension imagemlt is loaded and working!
NULL
