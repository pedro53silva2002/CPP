#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	_vectorBase = std::vector<int>();
	_dequeBase = std::deque<int>();
	_size = 0;
	/* for (std::map<std::string, float>::iterator i = _dataBase.begin(); i != _dataBase.end(); ++i) 
        std::cout << i->first << " " << i->second << std::endl; */
	//std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe::PmergeMe(char** list) {
	clock_t start = clock();
	//std::string input = list[1];
	//std::size_t found = input.find(' ');
	for (size_t i = 1; list[i]; i++)
    {
        for (size_t j = 0; list[i][j]; j++)
        {
            if (!isdigit(list[i][j]))
            {
                std::cerr << "Error: it needs to be all digits and only positive ones" << std::endl;
                exit (1);
            }
        }
		for (size_t k = 0; list[k]; k++)
		{
			if (atoi(list[i]) == atoi(list[k]) && i != k)
			{
				std::cerr << "Error: there are duplicate numbers" << std::endl;
				exit (1);
			}
		}
    }
	_vectorBase = std::vector<int>();
	_dequeBase = std::deque<int>();

	for (size_t i = 0; list[i]; i++) {
		_vectorBase.push_back(std::atoi(list[i]));
		_dequeBase.push_back(std::atoi(list[i]));
	}
	_size = _vectorBase.size();
	_managementTime = clock() - start;
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	//std::cout << "PmergeMe copy assignation called" << std::endl;
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	//std::cout << "PmergeMe assignation operator called" << std::endl;
	if (this != &src)
	{
		_vectorBase = src._vectorBase;
		_dequeBase = src._dequeBase;
	}
	/* if (this != &src)
	{
		_input = src.getInput();
		_intValue = src.getIntValue();
		_charValue = src.getCharValue();
		_doubleValue = src.getDoubleValue();
		_floatValue = src.getFloatValue();
		_type = src.getType();
	} */
	return *this;
}

PmergeMe::~PmergeMe()
{
	//std::cout << "PmergeMe descontructor called" << std::endl;
}

/* void PmergeMe::mergeVector(std::vector<int>& vector) {
	if (vector.size() <= 1)
		return;
	size_t mid = vector.size() / 2;
	std::vector<int> left(vector.begin(), vector.begin() + mid);
	std::vector<int> right(vector.begin() + mid, vector.end());
	mergeVector(left);
	mergeVector(right);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), vector.begin());
}

void PmergeMe::mergeDeque(std::deque<int>& deque) {
	if (deque.size() <= 1)
		return;
	size_t mid = deque.size() / 2;
	std::deque<int> left(deque.begin(), deque.begin() + mid);
	std::deque<int> right(deque.begin() + mid, deque.end());
	mergeDeque(left);
	mergeDeque(right);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), deque.begin());
} */

/* template <typename T>
T jacobsthalOrder(size_t n) {
    T seq;

    // Generate normal Jacobsthal numbers until >= n
    T J;
    J.push_back(0);
    J.push_back(1);

    while (J.back() < (int)n) {
        J.push_back(J[J.size() - 1] + 2 * J[J.size() - 2]);
    }

	std::cout << "J SIZE: " << J.size() << "\tSIZE: " << n << std::endl;
    // Now convert Jacobsthal numbers into insertion order
    // Ford–Johnson wants ranges like:
    // J(k), J(k)-1, ..., J(k-1)+1, then next block...
    for (size_t k = 2; k < J.size(); k++) {
        size_t a = J[k-1];
        size_t b = J[k];

        if (a >= n) break;

        size_t end = std::min(b, n);

        for (size_t i = end; i > a; --i)
            seq.push_back(i - 1);
    }

    return seq;
} */

template <typename T>
T jacobsthalOrder(size_t n) {
    T seq;
    T J;
    J.push_back(0);
    J.push_back(1);

    while (J.back() < (int)n) {
        J.push_back(J[J.size() - 1] + 2 * J[J.size() - 2]);
    }

    for (size_t k = 2; k < J.size(); k++) {
        size_t a = J[k-1];
        size_t b = J[k];
        if (a >= n) break;
        size_t end = std::min(b, n);
        for (size_t i = end; i > a; --i)
            seq.push_back(i - 1);
    }

    // Make sure all indices 0..n-1 are included
    for (size_t i = 0; i < n; ++i) {
        if (std::find(seq.begin(), seq.end(), i) == seq.end())
            seq.push_back(i);
    }

    return seq;
}


template <typename T>
void PmergeMe::binarySort(T &mainChain, int value) {
	//std::cout << "Value: " << value << "\t";
	int i = 0;
	int j = mainChain.size() - 1;
	if (mainChain.size() == 0)
	{
		mainChain.push_back(value);
		return;
	}
	if (mainChain.size() > 2) 
	{
		while (j - i > 1)
		{
			//std::cout << "J: " << j << "\ti: " << i << std::endl;
			int mid = (i + j) / 2;
			if (value < mainChain[mid])
				j = mid;
			else
				i = mid;
		}
	}
	if (value < mainChain[i])
	{
		//std::cout << "Inserting to the left of " << mainChain[i] << std::endl;
		//int oldnbr = mainChain[i];
		//int oldnbr2 = mainChain[i + 1];
		mainChain.insert(mainChain.begin() + i, value);
		//mainChain[i] = value;
		/* for (size_t k = i + 1; k < mainChain.size() + 1; k++)
		{
			int temp = mainChain[k];
			//mainChain.insert(mainChain.begin() + k, oldnbr);
			mainChain[k] = oldnbr;
			oldnbr = temp;
		} */
	} else if (value < mainChain[j])
	{
		//std::cout << "Inserting to the left of " << mainChain[j] << std::endl;
		mainChain.insert(mainChain.begin() + j, value);
	}
	else if (value > mainChain[j])
	{
		//std::cout << "Inserting to the right of " << mainChain[j] << std::endl;
		mainChain.insert(mainChain.begin() + j + 1, value);
	}
	//std::cout << "Inserting " << value << " between " << mainChain[i] << " and " << mainChain[j] << std::endl;
}

template <typename T>
void PmergeMe::mergeSort(T& container) {
	unsigned long pairSize = 1;
	int n = 0;
	if (container.size() <= 1)
		return;
	while (pairSize * 2 < container.size())
		pairSize += 1;
	//std::cout << "Pair size: " << pairSize << std::endl;
	std::pair<int, int> *pairs = new std::pair<int, int>[pairSize];
	if (container.size() % 2 != 0)
	{
		//std::cout << "Odd size detected" << std::endl;
		for (size_t i = 0; i < pairSize - 1; i++)
		{
			pairs[i] = std::make_pair(container[n], container[n + 1]);
			n+=2;
		}
		pairs[pairSize - 1] = std::make_pair(container[n], -1);
	}
	else
	{
		//std::cout << "Even size detected" << std::endl;
		for (size_t i = 0; i < pairSize; i++)
		{
			pairs[i] = std::make_pair(container[n], container[n + 1]);
			n+=2;
		}
	}
	/* std::cout << "Before: " << std::endl;
	for (size_t i = 0; i < pairSize; i++)
	{
		std::cout << "Pair " << i << ": " << pairs[i].first << ", " << pairs[i].second << std::endl;
	} */
	for (size_t i = 0; i < pairSize; i++)
	{
		if (pairs[i].first < pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	}
	/* std::cout << "After: " << std::endl;
	for (size_t i = 0; i < pairSize; i++)
	{
		std::cout << "Pair " << i << ": " << pairs[i].first << ", " << pairs[i].second << std::endl;
	} */
	T mainChain;
	T pendingChain;
	//std::cout << "Pair size: " << pairSize << std::endl;
	for (size_t i = 0; i < pairSize; i++)
	{
		mainChain.push_back(pairs[i].first);
		if (pairs[i].second != -1)
			pendingChain.push_back(pairs[i].second);
	}
	bool sorted = false;
	while (!sorted)
	{
		sorted = true;
		for (size_t i = 0; i < mainChain.size() - 1; i++)
		{
			if (mainChain[i] > mainChain[i + 1])
			{
				sorted = false;
				std::swap(mainChain[i], mainChain[i + 1]);
			}
		}
	}
	delete[] pairs;
	/* for (size_t i = 0; i < mainChain.size(); i++)
	{
		std::cout << mainChain[i] << " ";
	}
	std::cout << std::endl;
	for (size_t i = 0; i < pendingChain.size(); i++)
	{
		std::cout << pendingChain[i] << " ";
	}
	std::cout << std::endl; */
	//binarySort(mainChain, pendingChain[0]);
	T order = jacobsthalOrder<T>(pendingChain.size());
	//std::cout << "PENDING SIZE: " << pendingChain.size() << "\tORDER SIZE: " << order.size() << std::endl;
	for (size_t i = 0; i < order.size(); ++i)
	{
		//std::cout << order[i] << " ";
		binarySort(mainChain, pendingChain[order[i]]);
	}
	//std::cout << std::endl;
	container = mainChain;
	/* for (size_t i = 0; i < mainChain.size(); i++)
	{
		std::cout << mainChain[i] << " ";
	}
	std::cout << std::endl; */ 
	
}

void PmergeMe::pushswap() {
	//mergeSort(_vectorBase);
	std::cout << "Before: ";
	for (size_t i = 0; i < _size; i++)
	{
		std::cout << _vectorBase[i] << " ";
	}
	std::cout << std::endl;
	clock_t vectorStart = clock();
	mergeSort(_vectorBase);
	clock_t vectorDuration = clock() - vectorStart;
	clock_t dequeStart = clock();
	mergeSort(_dequeBase);
	clock_t dequeDuration = clock() - dequeStart;
	std::cout << "After: ";
	for (size_t i = 0; i < _size; i++)
	{
		std::cout << _vectorBase[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _size << " elements with std::vector : " << (double)(vectorDuration + _managementTime) * 1e6 / CLOCKS_PER_SEC << " us" << std::endl;
	std::cout << "Time to process a range of " << _size << " elements with std::deque : " << (double)(dequeDuration + _managementTime) * 1e6 / CLOCKS_PER_SEC << " us" << std::endl;
}

/* int PmergeMe::Jacobsthalnbr(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Jacobsthalnbr(n - 1) + 2 * Jacobsthalnbr(n - 2);
} */

/* void PmergeMe::PairInsertionSort(std::vector<int>& vec) {
	if (vec.size() <= 1)
		return;

	std::vector<std::pair<int, int>> pairs;
	for (size_t i = 0; i + 1 < vec.size(); i += 2) {
		if (vec[i] < vec[i + 1])
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
	}
	if (vec.size() % 2 != 0)
		pairs.push_back(std::make_pair(vec.back(), INT_MAX));

	std::vector<int> sorted;
	sorted.push_back(pairs[0].first);
	sorted.push_back(pairs[0].second);

	for (size_t i = 1; i < pairs.size(); i++) {
		int first = pairs[i].first;
		int second = pairs[i].second;

		auto it = std::lower_bound(sorted.begin(), sorted.end(), first);
		sorted.insert(it, first);

		it = std::lower_bound(sorted.begin(), sorted.end(), second);
		sorted.insert(it, second);
	}
	vec = sorted;
}

void PmergeMe::PairInsertionSort(std::deque<int>& deq) {
	if (deq.size() <= 1)
		return;

	std::deque<std::pair<int, int>> pairs;
	for (size_t i = 0; i + 1 < deq.size(); i += 2) {
		if (deq[i] < deq[i + 1])
			pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		else
			pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
	}
	if (deq.size() % 2 != 0)
		pairs.push_back(std::make_pair(deq.back(), INT_MAX));

	std::deque<int> sorted;
	sorted.push_back(pairs[0].first);
	sorted.push_back(pairs[0].second);

	for (size_t i = 1; i < pairs.size(); i++) {
		int first = pairs[i].first;
		int second = pairs[i].second;

		auto it = std::lower_bound(sorted.begin(), sorted.end(), first);
		sorted.insert(it, first);

		it = std::lower_bound(sorted.begin(), sorted.end(), second);
		sorted.insert(it, second);
	}
	deq = sorted;
} */