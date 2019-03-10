--TEST--
Check if imagemlt is loaded
--SKIPIF--
<?php
if (!extension_loaded('imagemlt')) {
	echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "imagemlt" is available';
?>
--EXPECT--
The extension "imagemlt" is available
