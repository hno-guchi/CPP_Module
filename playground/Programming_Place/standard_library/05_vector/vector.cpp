#if 0

vector
実行時に要素数を変更できる動的配列
#include <vector>
vectorはクラステンプレートなので、テンプレート実引数の指定が必要。
Allocator

namespace std {
	templete <typename T, typename Allocator = allocator<T> >
	class vector {};
}

サイズと容量
「容量」とは、実際に確保されている動的配列の要素数のこと(capacityメンバ関数で取得)
「サイズ」とは、動的配列内に実際に存在する要素数のこと（sizeメンバ関数で取得）。サイズが０かどうか知りたいときは（emptyメンバ関数）
capacity();, size();¸メンバ関数の戻り値は、std::vector::size_type型。これは、符号なし整数型。

要素のアクセス
範囲外アクセスに対する処理は、ないので注意が必要。
添字アクセス時には、容量の拡張は行われない。
有効な添字の上限値は「サイズ−１」なので注意。

代入
テンプレート実引数が同一であれば、代入演算子を使用してコピーができる。
また、assign();メンバ関数を使用することも可能。

追加・挿入
insert();を使用した場合、要素が途中に割り込んでくるので、後続の要素のメモリアドレスが変化する。
挿入位置より後ろの値は、改めて入れ直す必要がある。

削除
コンテナから要素を削除することとは、管理領域から外すこと。
外部でnew演算子を用いて確保された領域を持つオブジェクトを入れるコンテナでは、
明示的にdeleteする必要がある。
また、deleteする際はコンテナの要素から削除する前に行うこと。

erase();
その位置より後方にあった要素のメモリアドレスが変わり得るため、
それらの要素を指していた、ポインタ、参照、イテレータが無効になることに注意。
要素（サイズ）が減っても容量（キャパシティ）は減らない。
削除された要素の次の有効な要素を指すイテレータが返される。

メンバ関数
サイズの最大値を取得する
size_type	max_size() const;

事前にまとまった領域を確保する
void	reserve(size_type n);

vectorの容量を減らす書き方
std::vector<int>(target).swap(target);

先頭要素を参照
front();
（空の場合には、未定義動作）

末尾要素を参照
back();
（空の場合には、未定義動作）

要素のコピー
assign();

配列の末尾へ要素を追加する
push_back();

#endif

#include <iostream>
#include <vector>

typedef std::vector<int> IntVector;

// assignment
void	PrintVector(const IntVector& vector)
{
	const IntVector::size_type size = vector.size();
	for (IntVector::size_type i = 0; i < size; i++) {
		std::cout \
			<< "vector[" << i << "] : [" <<vector.at(i) << "]" \
			<< std::endl;
	}
	std::cout << std::endl;
}


int	main() {

	// sizeとcapacity
	{
		std::vector<int>	vector;

		for (int i = 0; i < 5; i++) {
			vector.push_back(i);
		}
		std::cout \
			<< "max_size(); [" << vector.max_size() << "]\n" \
			<< "    size(); [" << vector.size() << "]\n" \
			<< "capacity(); [" << vector.capacity() << "]" \
			<< std::endl;
		std::cout << std::endl;
	}

	{
		// reverse();
		std::vector<int>	vector;

		vector.reserve(10000);	// 10000以上の容量を確保する
		vector.push_back(0);	// 要素を１つ追加（サイズが１増える）

		std::cout \
			<< "BEFORE : capacity(); [" << vector.capacity() << "]" \
			<< std::endl;

		std::vector<int>(vector).swap(vector);

		std::cout \
			<< " AFTER : capacity(); [" << vector.capacity() << "]" \
			<< std::endl;
		std::cout << std::endl;
	}

	// Create and initialize
	{
		const int	a[] = {0, 1, 2, 3, 4};

		std::vector<int>	vector_1;			// empty
		std::vector<int>	vector_2(10);		// size == 10; Use default constructer
		std::vector<int>	vector_3(10, 3);	// size == 10; Use copy constructer
		std::vector<int>	vector_4(vector_2);		// Copy other vector
		std::vector<int>	vector_5(a, a + 5);	// iteratorで指定された範囲からコピー
	}

	// Access element
	{
		std::vector<int>	vector(10);

		try {
			vector.at(3) = 10;
			int	a = vector.at(3);

			std::cout << "a : [" << a << "]" << std::endl;

			vector.at(50) = 10; // Error access.

			// Not execute
			std::cout << "!!!!!" << std::endl;
		}
		catch (const std::out_of_range& exception) {
			std::cerr << exception.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::vector<int>					vector(10);
		const std::vector<int>::size_type	size = vector.size();

		for (int i = 0; i < static_cast<int>(size); i++) {
			vector[i] = i;
		}

		std::cout \
			<< "front(); ["<< vector.front() << "]" << std::endl;
		std::cout \
			<< " back(); ["<< vector.back() << "]" << std::endl;
		std::cout << std::endl;
	}

	{
		IntVector	vector;

		vector.assign(5, 3);
		PrintVector(vector);

		const int	a[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
		vector.assign(a, a + 10);
		PrintVector(vector);
		std::cout << std::endl;
	}

	// Add and Insert
	{
		std::vector<int>	vector;

		for (int i = 0; i < 5; i++) {
			vector.push_back(i);
		}
		PrintVector(vector);

		IntVector			vector_2(5, 3);
		IntVector::iterator	iter;

		iter = vector_2.insert(vector_2.end() - 1, 0);	// 末尾に０を挿入
		PrintVector(vector_2);

		vector_2.insert(iter, 3, 99);	// 0の手前に99を３個挿入
		PrintVector(vector_2);

		const int	a[] = {10, 11, 12};
		vector_2.insert(vector_2.begin(), a, a + 3);	// ある範囲から先頭へ挿入
		PrintVector(vector_2);
	}

	// Delete
	{
		// pop_back();
		std::vector<int *>	vector;

		vector.push_back(new int(10));
		delete vector.back();
		vector.pop_back();
	}

	// Delete
	{
		// erase();
	}
}
