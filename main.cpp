/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

#include <iostream>
#include <string>

struct T
{
    T( int v, const char* tString );   //1
    int value;  //2
    std::string name;  //3
};

T::T( int v, const char* tString )
{
    this->value = v;
    this->name = tString;
}

struct MyStruct1                                //4
{
    T* compare(T* a, T* b )
    {
        if( a != nullptr && b != nullptr )
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    } //5
      
};

struct U
{
    float member1 { 0 }, member2 { 0 };

    float multiplyMembers( float* newVal )      //12
    {
        if( newVal == nullptr )
        {
            return 0.f; 
        }

        std::cout << "My new member 1 value: " << this->member1 << std::endl;
        this->member1 = *newVal;
        std::cout << "My new member 2 updated value: " << this->member1 << std::endl;
        while( std::abs( this->member1 - this->member2) > 0.001f )
        {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */
            this->member2 += 1;
        }
        std::cout << "My new member 2 updated value: " << this->member2 << std::endl;
        return this->member1 * this->member2;
    }
};

struct MyStruct2
{
    static float multiplyStuff(U* that, float* newVal )        //10
    {
        if( that == nullptr || newVal == nullptr )
        {
            return 0.f;
        }
        
        std::cout << "U's member 1 value: " << that->member1 << std::endl;
        that->member1 = *newVal;
        std::cout << "U's member 2 updated value: " << that->member1 << std::endl;
        while( std::abs(that->member1 - that->member2) > 0.001f )
        {
            /*
             write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
             */
            that->member2 += 1;
        }
        std::cout << "U's member 2 updated value: " << that->member2 << std::endl;
        return that->member1 * that->member2;
    }
};
        
int main()
{
    T bob( 1, "Bob" );            //6
    T steve( 2, "Steve" );        //6
    
    MyStruct1 f;                  //7
    auto* smaller = f.compare( &bob, &steve );    //8
    std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    
    U shelly;
    float updatedValue = 5.f;
    std::cout << "[static func] Shelly's multiplied values: " << MyStruct2::multiplyStuff( &shelly, &updatedValue ) << std::endl;                  //11
    
    U ursla;
    std::cout << "[member func] Ursla's multiplied values: " << ursla.multiplyMembers( &updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
