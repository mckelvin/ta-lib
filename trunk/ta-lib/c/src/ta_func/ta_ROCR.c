/* TA-LIB Copyright (c) 1999-2002, Mario Fortier
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * - Neither name of author nor the names of its contributors
 *   may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* List of contributors:
 *
 *  Initial  Name/description
 *  -------------------------------------------------------------------
 *  MF       Mario Fortier
 *
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  112400 MF   Template creation.
 *
 */

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */

#ifndef TA_FUNC_H
   #include "ta_func.h"
#endif

#ifndef TA_UTILITY_H
   #include "ta_utility.h"
#endif

int TA_ROCR_Lookback( TA_Integer    optInTimePeriod_0 )  /* From 1 to TA_INTEGER_MAX */

/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */

   return optInTimePeriod_0;
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_ROCR - Rate of change ratio: (price/prevPrice)
 * 
 * Input  = TA_Real
 * Output = TA_Real
 * 
 * Optional Parameters
 * -------------------
 * optInTimePeriod_0:(From 1 to TA_INTEGER_MAX)
 *    Number of period
 * 
 * 
 */

TA_RetCode TA_ROCR( TA_Libc      *libHandle,
                    TA_Integer    startIdx,
                    TA_Integer    endIdx,
                    const TA_Real inReal_0[],
                    TA_Integer    optInTimePeriod_0, /* From 1 to TA_INTEGER_MAX */
                    TA_Integer   *outBegIdx,
                    TA_Integer   *outNbElement,
                    TA_Real       outReal_0[] )
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */

   int inIdx, outIdx, trailingIdx;
   TA_Real tempReal;

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   (void)libHandle; /* Get ride of warning if unused. */

#ifndef TA_FUNC_NO_RANGE_CHECK

   /* Validate the requested output range. */
   if( startIdx < 0 )
      return TA_OUT_OF_RANGE_START_INDEX;
   if( (endIdx < 0) || (endIdx < startIdx))
      return TA_OUT_OF_RANGE_END_INDEX;

   /* Validate the parameters. */
   if( !inReal_0 ) return TA_BAD_PARAM;
   /* min/max are checked for optInTimePeriod_0. */
   if( optInTimePeriod_0 == TA_INTEGER_DEFAULT )
      optInTimePeriod_0 = 10;
   else if( (optInTimePeriod_0 < 1) || (optInTimePeriod_0 > 2147483647) )
      return TA_BAD_PARAM;

   if( outReal_0 == NULL )
      return TA_BAD_PARAM;

#endif /* TA_FUNC_NO_RANGE_CHECK */

/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   /* The interpretation of the rate of change varies widely depending
    * which software and/or books you are refering to.
    *
    * The following is the table of Rate-Of-Change implemented in TA-LIB:
    *       MOM     = (price - prevPrice)         [Momentum]
    *       ROC     = ((price/prevPrice)-1)*100   [Rate of change]
    *       ROCP    = (price-prevPrice)/prevPrice [Rate of change Percentage]
    *       ROCR    = (price/prevPrice)           [Rate of change ratio]
    *       ROCR100 = (price/prevPrice)*100       [Rate of change ratio 100 Scale]
    *
    * Here are the equivalent function in other software:
    *       TA-Lib  |   Tradestation   |    Metastock         
    *       =================================================
    *       MOM     |   Momentum       |    ROC (Point)
    *       ROC     |   ROC            |    ROC (Percent)
    *       ROCP    |   PercentChange  |    -     
    *       ROCR    |   -              |    -
    *       ROCR100 |   -              |    MO
    *
    * The MOM function is the only one who is not normalized, and thus
    * should be avoided for comparing different time serie of prices.
    * 
    * ROC and ROCP are centered at zero and can have positive and negative
    * value. Here are some equivalence:
    *    ROC = ROCP/100 
    *        = ((price-prevPrice)/prevPrice)/100
    *        = ((price/prevPrice)-1)*100
    *
    * ROCR and ROCR100 are ratio respectively centered at 1 and 100 and are
    * always positive values.
    */

   /* Move up the start index if there is not
    * enough initial data.
    */
   if( startIdx < optInTimePeriod_0 )
      startIdx = optInTimePeriod_0;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      return TA_SUCCESS;
   }

   /* Calculate Rate of change Ratio: (price / prevPrice) */
   outIdx      = 0;
   inIdx       = startIdx;
   trailingIdx = startIdx - optInTimePeriod_0;

   while( inIdx <= endIdx )
   {
      tempReal = inReal_0[trailingIdx++];
      if( tempReal != 0.0 )
         outReal_0[outIdx++] = (inReal_0[inIdx] / tempReal);
      else
         outReal_0[outIdx++] = 0.0; 
         
      inIdx++;
   }

   /* Set output limits. */
   *outNbElement = outIdx;
   *outBegIdx    = startIdx;

   return TA_SUCCESS;
}

