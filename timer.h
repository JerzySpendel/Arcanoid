/*
 * =====================================================================================
 *
 *       Filename:  Timer.h
 *
 *    Description:  Timer class
 *
 *        Version:  1.0
 *        Created:  07/05/14 00:51:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Timer{
	unsigned int ts1; /*  Timestamp */
	unsigned int ts2; /*  Timestamp 2 */
	unsigned int min_diff;
	public:
	
	Timer(int);
	unsigned int Tick();

};
