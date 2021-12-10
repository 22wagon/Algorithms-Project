#ifndef MENU_HPP
#define MENU_HPP

#include <vector>

class Menu {
    public:
        Menu();

        virtual ~Menu();

        int Start();

        std::vector<int> elementsToOrder;
        std::vector<int> tempElement;
        std::vector<int> output;

    private:
        void ShowMenu();

        int StartMenu();

        long long MeasureTime(std::vector<int>& a, int choice);

        void SortArray();

        void HalfSortArray();

        void ReversedArray();

        void FillData();
        
        void InsertionSort(std::vector<int>& a);

        void SelectionSort(std::vector<int>& a);

        void BubbleSort(std::vector<int>& a);

        void MergeSort(int fir, int las);

        void Merge(int firStart, int firEnd, int lasStart, int lasEnd);

        void QuickSort(std::vector<int>&, int left, int right);

        void HeapSort(std::vector<int>&, int num);

        void CountingSort(std::vector<int>&);

        void RadixSort(std::vector<int>&);

        int GetMax(std::vector<int>&);

        void Print100Smallers(std::vector<int>& elementsToPrint);

        void CalculateHFactors(std::vector<unsigned int>& h_factors,
                               const std::vector<int>& elementsToOrder);



        std::vector<int> randomItems;

};

#endif // MENU_HPP
