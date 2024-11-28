import subprocess

assert ('1 2 3 4 5 6 7 8 9 10' == subprocess.run(["./cocktailshakingsort", "./tests/bad_for_cocktailshaking.txt"], text=True, capture_output=True).stdout.rstrip(' \n'))
assert ('1 2 3 4 5 6 7 8' == subprocess.run(["./cocktailshakingsort", "./tests/normal_for_cocktailshaking.txt"], text=True, capture_output=True).stdout.rstrip(' \n'))

assert ('1 2 3 4 5 6 7 8 9 10' == subprocess.run(["./heapsort", "./tests/normal_for_heap.txt"], text=True, capture_output=True).stdout.rstrip(' \n'))
assert ('1 2 3 4 5 6 7 8 9 10' == subprocess.run(["./heapsort", "./tests/bad_for_heap.txt"], text=True, capture_output=True).stdout.rstrip(' \n'))

assert ('100 200 300 400 1000' == subprocess.run(["./countingsort", "./tests/bad_for_counting.txt"], text=True, capture_output=True).stdout.rstrip(' \n'))
assert ('1 2 3 3 4 5 5 6 6' == subprocess.run(["./countingsort", "./tests/normal_for_counting.txt"], text=True, capture_output=True).stdout.rstrip(' \n'))