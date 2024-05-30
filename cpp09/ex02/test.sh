#!/bin/bash

# 引数として渡された実行ファイル名を変数に格納
exec_name=$1

# 引数が渡されているか確認
if [ -z "$exec_name" ]; then
  echo "実行ファイル名を指定してください。"
  exit 1
fi

# 実行ファイルが存在するか確認
if [ ! -f "$exec_name" ]; then
  echo "指定された実行ファイルが見つかりません: $exec_name"
  exit 1
fi

# xに入る値のリスト
values=(1 2 3 4 5 6 7 8 9 10 21 100 1000 3000 10000)

# xの各値について処理
for x in "${values[@]}"; do
    # 各xに対して100回の繰り返し
    for i in {1..30}; do
        # ランダムな数列を生成し、改行をスペースに置換してコマンドを実行
        ./$exec_name $(jot -r $x 0 999999 | tr '\n' ' ')
    done
done
