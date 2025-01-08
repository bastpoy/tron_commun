make bonus;

valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet  ./pipex "assets/deepthought.txt" "/usr/bin/ct -e" "wc" "outfile.txt"; echo $?
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet  ./pipex "assets/deepthought.txt" "cat -e" "wc" "outfile.txt"; echo $?
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet  ./pipex "assets/deepthought.txt" "ct -e" "wc -a" "outfile.txt"; echo $?
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet  ./pipex "assets/deepthought.txt" "/usr/bin/cat -e" "/usr/bin/wa" "outfile.txt"; echo $?
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet  ./pipex "assets/deepthought.txt" "/usr/bin/cat -e" "/usr/bin/wc" "outfile.txt"; echo $?
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet  ./pipex infile.txt "sed "s/And/But/"" "grep But" "outfile.txt"; echo $?
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet ./pipex "assets/deepthought.txt" "/usr/bin/ct -e" "wc" "outfile.txt"; 
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet ./pipex "assets/deepthought.txt" "ct -e" "wc" "outfile.txt"; 
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet ./pipex ./assets/deepthought.txt 'grep Now' 'wc -w' outfile.txt;
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet ./pipex "not-existing/deepthought.txt" "grep Now" "wc -w" outfile.txt;
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet ./pipex "assets/deepthought.txt" "grep Now" "wc -w" "not-existing/outfile.txt";
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet ./pipex "assets/deepthought.txt" "./assets/not-executable" "cat" "outfile.txt";
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet ./pipex "assets/deepthought.txt" "cat" "./assets/not-executable" "outfile.txt";
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet ./pipex "/dev/null" "env_var" "cat" "outfile.txt";
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet ./pipex \"assets/deepthought.txt\" cat \"hostname\" \"outfile.txt\";
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet ./pipex "assets/deepthought.txt" "cat" "notexisting" "outfile.txt";
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet ./pipex "assets/deepthought.txt" "notexisting" "wc -w" "outfile.txt";
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet ./pipex "assets/deepthought.txt" "grep Now" "$(which cat)" "outfile.txt";
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet ./pipex "assets/infile.txt" cat cat ls cat wc "outfile.txt";
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet ./pipex "assets/infile.txt" 'sed "s/And/But/"' 'grep But' "outfile.txt";
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet ./pipex "assets/infile.txt" './assets/script.sh' 'wc' "outfile.txt";
valgrind --leak-check=full --show-leak-kinds=all --undef-value-errors=no --error-exitcode=240 --errors-for-leak-kinds=all --track-fds=yes -s --quiet ./pipex "assets/infile.txt" 'cat' './assets/middle_fail.sh' "outfile.txt";
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --leak-check=full --trace-children=yes ./pipex "assets/infile.txt" 'cat' 'cat' 'cat' 'cat' "outfile.txt";

valgrind   ./pipex "assets/deepthought.txt" "/usr/bin/ct -e" "wc" "outfile.txt"; echo $?
valgrind   ./pipex "assets/deepthought.txt" "cat -e" "wc" "outfile.txt"; echo $?
valgrind   ./pipex "assets/deepthought.txt" "ct -e" "wc -a" "outfile.txt"; echo $?
valgrind   ./pipex "assets/deepthought.txt" "/usr/bin/cat -e" "/usr/bin/wa" "outfile.txt"; echo $?
valgrind   ./pipex "assets/deepthought.txt" "/usr/bin/cat -e" "/usr/bin/wc" "outfile.txt"; echo $?
valgrind   ./pipex infile.txt "sed "s/And/But/"" "grep But" "outfile.txt"; echo $?
valgrind  ./pipex "assets/deepthought.txt" "/usr/bin/ct -e" "wc" "outfile.txt"; 
valgrind  ./pipex "assets/deepthought.txt" "ct -e" "wc" "outfile.txt"; 
valgrind  ./pipex ./assets/deepthought.txt 'grep Now' 'wc -w' outfile.txt;
valgrind  ./pipex "not-existing/deepthought.txt" "grep Now" "wc -w" outfile.txt;
valgrind  ./pipex "assets/deepthought.txt" "grep Now" "wc -w" "not-existing/outfile.txt";
valgrind  ./pipex "assets/deepthought.txt" "./assets/not-executable" "cat" "outfile.txt";
valgrind  ./pipex "assets/deepthought.txt" "cat" "./assets/not-executable" "outfile.txt";
valgrind  ./pipex "/dev/null" "env_var" "cat" "outfile.txt";
valgrind  ./pipex \"assets/deepthought.txt\" cat \"hostname\" \"outfile.txt\";
valgrind  ./pipex "assets/deepthought.txt" "cat" "notexisting" "outfile.txt";
valgrind  ./pipex "assets/deepthought.txt" "notexisting" "wc -w" "outfile.txt";
valgrind  ./pipex "assets/deepthought.txt" "grep Now" "$(which cat)" "outfile.txt";
valgrind  ./pipex "assets/infile.txt" cat cat ls cat wc "outfile.txt";
valgrind  ./pipex "assets/infile.txt" 'sed "s/And/But/"' 'grep But' "outfile.txt";
valgrind  ./pipex "assets/infile.txt" './assets/script.sh' 'wc' "outfile.txt";
valgrind  ./pipex "assets/infile.txt" 'cat' './assets/middle_fail.sh' "outfile.txt";
