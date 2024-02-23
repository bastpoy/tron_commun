#!/bin/bash
make bonus;

echo PIPEX > pipex.txt;
echo >> pipex.txt;
echo PIPE > pipe.txt;
echo >> pipe.txt;

echo TEST_0 >> pipex.txt;
echo TEST_0 >> pipe.txt;
echo > outfile.txt
./pipex "assets/deepthought.txt" "/usr/bin/ct -e" "wc" "outfile.txt"; echo $? >> pipex.txt 2>&1; echo ERROR_CODE:$? >> pipex.txt 2>&1; echo -n "OUTPUT: " >> pipex.txt; cat outfile.txt >> pipex.txt;
echo > outfile.txt
{<./assets/deepthought.txt /usr/bin/ct -e | wc >outfile.txt;} 2>> pipe.txt; echo ERROR_CODE:$? >> pipe.txt 2>&1; echo -n "OUTPUT: " >> pipe.txt; cat outfile.txt >> pipe.txt;
echo >> pipex.txt;
echo >> pipe.txt;
sleep 1

echo TEST_0_1 >> pipex.txt;
echo TEST_0_1 >> pipe.txt;
echo > outfile.txt
./pipex "assets/deepthought.txt" "ct -e" "wc" "outfile.txt"; echo $? >> pipex.txt 2>&1; echo ERROR_CODE:$? >> pipex.txt 2>&1; echo -n "OUTPUT: " >> pipex.txt; cat outfile.txt >> pipex.txt;
echo > outfile.txt
{<./assets/deepthought.txt ct -e | wc >outfile.txt;} 2>> pipe.txt; echo ERROR_CODE:$? >> pipe.txt 2>&1; echo -n "OUTPUT: " >> pipe.txt; cat outfile.txt >> pipe.txt;
echo >> pipex.txt;
echo >> pipe.txt;
sleep 1


echo TEST_1 >> pipex.txt;
echo TEST_1 >> pipe.txt;
echo > outfile.txt
./pipex ./assets/deepthought.txt 'grep Now' 'wc -w' outfile.txt >> pipex.txt 2>&1; echo ERROR_CODE:$? >> pipex.txt 2>&1; echo -n "OUTPUT: " >> pipex.txt; cat outfile.txt >> pipex.txt;
echo > outfile.txt
{<./assets/deepthought.txt grep Now | wc -w >outfile.txt;} 2>> pipe.txt; echo ERROR_CODE:$? >> pipe.txt 2>&1; echo -n "OUTPUT: " >> pipe.txt; cat outfile.txt >> pipe.txt;
echo >> pipex.txt;
echo >> pipe.txt;
sleep 1

echo TEST_2 >> pipex.txt;
echo TEST_2 >> pipe.txt;
echo > outfile.txt
./pipex "not-existing/deepthought.txt" "grep Now" "wc -w" outfile.txt >> pipex.txt 2>&1; echo ERROR_CODE:$? >> pipex.txt 2>&1; echo -n "OUTPUT: " >> pipex.txt; cat outfile.txt >> pipex.txt;
{<not-existing/deepthought.txt cat | wc -w >outfile.txt;} 2>> pipe.txt; echo ERROR_CODE:$? >> pipe.txt 2>&1; echo -n "OUTPUT: " >> pipe.txt; cat outfile.txt >> pipe.txt;
echo >> pipex.txt;
echo >> pipe.txt;
sleep 1

echo TEST_3 >> pipex.txt;
echo TEST_3 >> pipe.txt;
echo > outfile.txt
./pipex "assets/deepthought.txt" "grep Now" "wc -w" "not-existing/outfile.txt" >> pipex.txt 2>&1; echo ERROR_CODE:$? >> pipex.txt 2>&1; echo -n "OUTPUT: " >> pipex.txt; cat outfile.txt >> pipex.txt;
{<assets/deepthought.txt grep Now | wc -w >not-existing/outfile.txt;} 2>> pipe.txt; echo ERROR_CODE:$? >> pipe.txt 2>&1; echo -n "OUTPUT: " >> pipe.txt; cat outfile.txt >> pipe.txt;
echo >> pipex.txt;
echo >> pipe.txt;
sleep 1

echo TEST_4 >> pipex.txt;
echo TEST_4 >> pipe.txt;
echo > outfile.txt
./pipex "assets/deepthought.txt" "./assets/not-executable" "cat" "outfile.txt" >> pipex.txt 2>&1; echo ERROR_CODE:$? >> pipex.txt 2>&1; echo "OUTPUT: " >> pipex.txt; cat outfile.txt >> pipex.txt;
{<assets/deepthought.txt ./assets/not-executable | cat >outfile.txt;} 2>> pipe.txt; echo ERROR_CODE:$? >> pipe.txt 2>&1; echo "OUTPUT: " >> pipe.txt; cat outfile.txt >> pipe.txt;
echo >> pipex.txt;
echo >> pipe.txt;
sleep 1

echo TEST_5 >> pipex.txt;
echo TEST_5 >> pipe.txt;
echo > outfile.txt
./pipex "assets/deepthought.txt" "cat" "./assets/not-executable" "outfile.txt" >> pipex.txt 2>&1; echo ERROR_CODE:$? >> pipex.txt 2>&1; echo "OUTPUT: " >> pipex.txt; cat outfile.txt >> pipex.txt;
{<assets/deepthought.txt cat | ./assets/not-executable >outfile.txt;} 2>> pipe.txt; echo ERROR_CODE:$? >> pipe.txt 2>&1; echo "OUTPUT: " >> pipe.txt; cat outfile.txt >> pipe.txt;
echo >> pipex.txt;
echo >> pipe.txt;
sleep 1

echo TEST_6 >> pipex.txt;
echo TEST_6 >> pipe.txt;
echo > outfile.txt
export VAR1="hello"; export VAR2="world"; ./pipex "/dev/null" "env_var" "cat" "outfile.txt" >> pipex.txt 2>&1; echo ERROR_CODE:$? >> pipex.txt 2>&1; echo "OUTPUT: " >> pipex.txt; cat outfile.txt >> pipex.txt;
{<"/dev/null" "env_var" | "cat" >outfile.txt;} 2>> pipe.txt; echo ERROR_CODE:$? >> pipe.txt 2>&1; echo  "OUTPUT: " >> pipe.txt; cat outfile.txt >> pipe.txt;
echo >> pipex.txt;
echo >> pipe.txt;
sleep 1

echo TEST_7 >> pipex.txt;
echo TEST_7 >> pipe.txt;
echo > outfile.txt
./pipex \"assets/deepthought.txt\" cat \"hostname\" \"outfile.txt\" >> pipex.txt 2>&1; echo ERROR_CODE:$? >> pipex.txt 2>&1; echo "OUTPUT: " >> pipex.txt; cat outfile.txt >> pipex.txt;
{< \"assets/deepthought.txt\" \"cat\" | \"hostname\">\"outfile.txt\";} 2>> pipe.txt; echo ERROR_CODE:$? >> pipe.txt 2>&1; echo -n "OUTPUT: " >> pipe.txt; cat outfile.txt >> pipe.txt;
echo >> pipex.txt;
echo >> pipe.txt;
sleep 1

echo TEST_8 >> pipex.txt;
echo TEST_8 >> pipe.txt;
echo > outfile.txt
./pipex "assets/deepthought.txt" "cat" "notexisting" "outfile.txt" >> pipex.txt 2>&1; echo ERROR_CODE:$? >> pipex.txt 2>&1; echo "OUTPUT: " >> pipex.txt; cat outfile.txt >> pipex.txt;
{<assets/deepthought.txt cat | notexisting >outfile.txt;} 2>> pipe.txt; echo ERROR_CODE:$? >> pipe.txt 2>&1; echo "OUTPUT: " >> pipe.txt; cat outfile.txt >> pipe.txt;
echo >> pipex.txt;
echo >> pipe.txt;
sleep 1

echo TEST_9 >> pipex.txt;
echo TEST_9 >> pipe.txt;
echo > outfile.txt
./pipex "assets/deepthought.txt" "notexisting" "wc -w" "outfile.txt" >> pipex.txt 2>&1; echo ERROR_CODE:$? >> pipex.txt 2>&1; echo -n "OUTPUT: " >> pipex.txt; cat outfile.txt >> pipex.txt;
{<assets/deepthought.txt notexisting | wc -w >outfile.txt;} 2>> pipe.txt; echo ERROR_CODE:$? >> pipe.txt 2>&1; echo -n "OUTPUT: " >> pipe.txt; cat outfile.txt >> pipe.txt;
echo >> pipex.txt;
echo >> pipe.txt;
sleep 1

echo TEST_10 >> pipex.txt;
echo TEST_10 >> pipe.txt;
echo > outfile.txt
./pipex "assets/deepthought.txt" "grep Now" "$(which cat)" "outfile.txt" >> pipex.txt 2>&1; echo ERROR_CODE:$? >> pipex.txt 2>&1; echo -n "OUTPUT: " >> pipex.txt; cat outfile.txt >> pipex.txt;
{<assets/deepthought.txt grep Now | $(which cat) >outfile.txt;} 2>> pipe.txt; echo ERROR_CODE:$? >> pipe.txt 2>&1; echo -n "OUTPUT: " >> pipe.txt; cat outfile.txt >> pipe.txt;
echo >> pipex.txt;
echo >> pipe.txt;
sleep 1

echo TEST_11 >> pipex.txt;
echo TEST_11 >> pipe.txt;
echo > outfile.txt
time ./pipex "assets/infile.txt" "sleep 1" "sleep 3" "sleep 5" "ls" "outfile.txt" >> pipex.txt 2>&1; echo ERROR_CODE:$? >> pipex.txt 2>&1; echo -n "OUTPUT: " >> pipex.txt; cat outfile.txt >> pipex.txt;
time {<assets/infile.txt sleep 1 | sleep 3 | sleep 5 | ls>outfile.txt;} 2>> pipe.txt; echo ERROR_CODE:$? >> pipe.txt 2>&1; echo -n "OUTPUT: " >> pipe.txt; cat outfile.txt >> pipe.txt;
echo >> pipex.txt;
echo >> pipe.txt;
sleep 1

echo TEST_12 >> pipex.txt;
echo TEST_12 >> pipe.txt;
echo > outfile.txt
time ./pipex "assets/infile.txt" "sleep 5" "sleep 3" "sleep 1" "ls" "outfile.txt" >> pipex.txt 2>&1; echo ERROR_CODE:$? >> pipex.txt 2>&1; echo -n "OUTPUT: " >> pipex.txt; cat outfile.txt >> pipex.txt;
time {<assets/infile.txt sleep 5 | sleep 3 | sleep 1 | ls>outfile.txt;} 2>> pipe.txt; echo ERROR_CODE:$? >> pipe.txt 2>&1; echo -n "OUTPUT: " >> pipe.txt; cat outfile.txt >> pipe.txt;
echo >> pipex.txt;
echo >> pipe.txt;
sleep 1

echo TEST_13 >> pipex.txt;
echo TEST_13 >> pipe.txt;
echo > outfile.txt
time ./pipex "assets/infile.txt" "sleep 1" "sleep 5" "sleep 3" "ls" "outfile.txt" >> pipex.txt 2>&1; echo ERROR_CODE:$? >> pipex.txt 2>&1; echo -n "OUTPUT: " >> pipex.txt; cat outfile.txt >> pipex.txt;
time {<assets/infile.txt sleep 1 | sleep 5 | sleep 3 | ls>outfile.txt;} 2>> pipe.txt; echo ERROR_CODE:$? >> pipe.txt 2>&1; echo -n "OUTPUT: " >> pipe.txt; cat outfile.txt >> pipe.txt;
echo >> pipex.txt;
echo >> pipe.txt;
sleep 1

echo TEST_14 >> pipex.txt;
echo TEST_14 >> pipe.txt;
echo > outfile.txt
./pipex "assets/infile.txt" cat cat ls cat wc "outfile.txt" >> pipex.txt 2>&1; echo ERROR_CODE:$? >> pipex.txt 2>&1; echo -n "OUTPUT: " >> pipex.txt; cat outfile.txt >> pipex.txt;
{<assets/infile.txt cat | cat | ls | cat | wc>outfile.txt;} 2>> pipe.txt; echo ERROR_CODE:$? >> pipe.txt 2>&1; echo -n "OUTPUT: " >> pipe.txt; cat outfile.txt >> pipe.txt;
echo >> pipex.txt;
echo >> pipe.txt;
sleep 1

echo TEST_15 >> pipex.txt;
echo TEST_15 >> pipe.txt;
echo > outfile.txt
./pipex "assets/infile.txt" 'sed "s/And/But/"' 'grep But' "outfile.txt" >> pipex.txt 2>&1; echo ERROR_CODE:$? >> pipex.txt 2>&1; echo -n "OUTPUT: " >> pipex.txt; cat outfile.txt >> pipex.txt;
{<assets/infile.txt sed "s/And/But/" | grep But>outfile.txt;} 2>> pipe.txt; echo ERROR_CODE:$? >> pipe.txt 2>&1; echo -n "OUTPUT: " >> pipe.txt; cat outfile.txt >> pipe.txt;
echo >> pipex.txt;
echo >> pipe.txt;
sleep 1

echo TEST_16 >> pipex.txt;
echo TEST_16 >> pipe.txt;
echo > outfile.txt
./pipex "assets/infile.txt" './assets/script.sh' 'wc' "outfile.txt" >> pipex.txt 2>&1; echo ERROR_CODE:$? >> pipex.txt 2>&1; echo -n "OUTPUT: " >> pipex.txt; cat outfile.txt >> pipex.txt;
{<assets/infile.txt "./assets/script.sh" | wc>outfile.txt;} 2>> pipe.txt; echo ERROR_CODE:$? >> pipe.txt 2>&1; echo -n "OUTPUT: " >> pipe.txt; cat outfile.txt >> pipe.txt;
echo >> pipex.txt;
echo >> pipe.txt;
sleep 1

echo TEST_17 >> pipex.txt;
echo TEST_17 >> pipe.txt;
echo > outfile.txt
./pipex "assets/infile.txt" 'cat' './assets/middle_fail.sh' "outfile.txt" >> pipex.txt 2>&1; echo ERROR_CODE:$? >> pipex.txt 2>&1; echo -n "OUTPUT: " >> pipex.txt; cat outfile.txt >> pipex.txt;
{<assets/infile.txt "cat" | ./assets/middle_fail.sh>outfile.txt;} 2>> pipe.txt; echo ERROR_CODE:$? >> pipe.txt 2>&1; echo -n "OUTPUT: " >> pipe.txt; cat outfile.txt >> pipe.txt;
echo >> pipex.txt;
echo >> pipe.txt;
sleep 1