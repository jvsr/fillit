#!/bin/sh

echo "test1"
time ./fillit test/valid_sample.1.fillit
echo "\ntest2"
time ./fillit test/valid_sample.2.fillit
echo "\ntest3"
time ./fillit test/valid_sample.3.fillit
echo "\ntest4"
time ./fillit test/valid_sample.4.fillit
echo "\ntest5"
time ./fillit test/valid_sample.5.fillit
echo "\ntest6"
time ./fillit test/valid_sample.6.fillit
echo "\ntest7"
time ./fillit test/valid_sample.7.fillit
echo "\ntest8"
time ./fillit test/valid_sample.8.fillit
echo "\ntest9"
time ./fillit test/valid_sample.9.fillit
echo "\ntest10"
time ./fillit test/valid_sample.10.fillit
echo "\ntest11 (will take around 60 seconds ;) )"
time ./fillit test/valid_sample.11.fillit