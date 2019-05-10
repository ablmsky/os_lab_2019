compilegcc utils.c find_min_max.c parallel_min_max.c -o minMaxPR_LL.exe
./minMaxPR_LL.exe --seed 1234 --array 100000 --pnum 40000
echo =============================================
./minMaxPR_LL.exe --seed 1234 --array 1000000 --pnum 4 --by_files