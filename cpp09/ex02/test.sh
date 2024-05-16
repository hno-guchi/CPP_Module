#!/bin/bash

# xに入る値のリスト
values=(1 2 3 4 5 6 7 8 9 10 100 1000 3000 10000)

# xの各値について処理
for x in "${values[@]}"; do
    # 各xに対して100回の繰り返し
    for i in {1..100}; do
        # ランダムな数列を生成し、改行をスペースに置換してコマンドを実行
        ./PmergeMe $(jot -r $x 0 999999 | tr '\n' ' ')
    done
done

