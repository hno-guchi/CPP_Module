template <typename CONTAINER>
CONTAINER	PmergeMe::sort(CONTAINER container) {
	try {
		std::clock_t	start = std::clock();
		CONTAINER		ret = this->mergeInsertionSort(container);
		std::clock_t	finish = std::clock();
		this->msTime_ = static_cast<double>(finish - start) / CLOCKS_PER_SEC * 1000.0;
		return (ret);
	} catch (std::exception &e) {
		throw;
	}
}

template <typename CONTAINER>
CONTAINER	PmergeMe::mergeInsertionSort(CONTAINER container) {
	return (container);
}

