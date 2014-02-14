#include <algorithm>

int* p=find(myints,myints+4,30);         //search for 30 and returns pointer/iterator
auto it=find(v.begin(),v.end(),30);

auto it=find_end(v.begin(),v.end(),myints,myints+4);    //from the end search

auto it=find_first_of(v.begin(),v.end(),myints,myints+4); //find_first_match,if none,return last elements

auto it=adjacent_find(v.begin(),v.end());                //gives first pair of adjacent repeated elements,last element otherwise

int val=count(myints,myints+8,10);                       //occurence of 10

mypair=mismatch(v.begin(),v.end(),myints);
cout<<"first mismatch on v"<<*mypair.first;
cout<<"first mismatch on myints"<<*mypair.second;

if(equal(v.begin(),v.end(),myints));   //check if equal

auto it=search(v.begin(),v.end(),myints,myints+4);          //found value/last iterator

auto it=search_n(v.begin(),v.end(),2,10);                   //return position where 2 10's occur

copy(myints,myints+7,v.begin());                            //copy to v
copy_backward(myints,myints+7,v.begin());                   //copy to v backwards..

swap(v1,v2);                                                //swaps values of two vectors

swap_ranges(v1.begin()+1,v1.end()-1,v2.begin());            //swaps within range

iter_swap(v1.begin(),v2.begin());                           //swaps first element from both vectors

replace(v1.begin(),v1.end(),20,99); 						//replace all 20's with 99
replace_copy(v1.begin(),v1.end(),v2.begin(),20,99); 		//stores answer into v2

fill(v.begin(),v.begin()+4,5);								//fill first 4 elements with 5;
fill_n(v.begin(),4,20);									    //fill first 4 elements with 20;

auto it=remove(v.begin(),v.end(),5);						//removes all 5;
remove_copy(v.begin(),v.end(),v2.begin(),5);				//returns copy to v2;

auto it=unique(v.begin(),v.end());                          //only unique values..
it=unique_copy(v.begin(),v.end(),v2.begin());				//unique copy to v2;

reverse(v.begin(),v.end());									//reverses stl
reverse_copy(v.begin(),v.end(),v2.begin());					//reverses and returns a copy.

rotate(v.begin(),v.begin()+3,v.end());						//rotates at 3rd position
rotate_copy(v.begin(),v.begin()+3,v.end(),v2.begin());		//copy to v2

random_shuffle(v.begin(),v.end());							//shuffles vector randomly

sort(v.begin(),v.end());
sort(v.begin(),v.end()+3);									//sorts only first 3 elements.

n_element(v.begin(),v.begin+3,v.end());						//rearranges in such a way that 3rd position element will be sorted array value and the others are not

bool t=next_permutation(v.begin(),v.end());                 //gives next_permutation of v on lexicographical order


