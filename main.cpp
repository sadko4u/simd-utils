/*
 * main.cpp
 *
 *  Created on: 16 февр. 2018 г.
 *      Author: sadko
 */

#include <dsp.h>

void do_math()
{
    dsp::context_t ctx;
    dsp::start(&ctx);

    dsp::example_function();

    dsp::finish(&ctx);
}

int main()
{
    dsp::init();

    do_math();

    return 0;
}


