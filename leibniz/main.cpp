#include <iomanip>
#include <boost/timer/timer.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/function/sum.hpp>
#include <iacaMarks.h>

template< typename FType > FType calcPi();

int main()
{
    boost::timer::cpu_timer timer;

    timer.start();
    double pi = calcPi<double>();
    timer.stop();

    std::cout << "Pi: " << std::setprecision( 20 ) << pi << std::endl;
    std::cout << timer.format();

    return 0;
}


template< typename FType > FType calcPi()
{
    using dpack = boost::simd::pack<FType, 4*boost::simd::pack<FType>::static_size>;

    dpack div;
    dpack one;
    dpack sum = dpack( 0 );
    dpack step = dpack( 2 * dpack::static_size );

    FType val = -1;
    FType fac = 3;
    for( size_t i = 0; i < dpack::static_size; ++i )
    {
        one[ i ] = val;
        div[ i ] = fac;
        val *= -1;
        fac += 2;
    }

        IACA_START
    for( size_t i = 0; i < 1024ull*1024ull*1024ull*16ull / dpack::static_size ; ++i )
    {
        sum += one / div;
        div += step;
    }
        IACA_END

    return 4 * (1 + boost::simd::sum( sum ) );
}

