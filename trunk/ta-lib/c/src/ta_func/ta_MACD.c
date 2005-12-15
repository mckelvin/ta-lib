/* TA-LIB Copyright (c) 1999-2005, Mario Fortier
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
 *  JPP      JP Pienaar (j.pienaar@mci.co.za)
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  112400 MF   Template creation.
 *  052603 MF   Adapt code to compile with .NET Managed C++
 *  080403 JPP  Fix #767653 for logic when swapping periods.
 *
 */

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */    #include "TA-Lib-Core.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (NAMESPACE(TA_RetCode)TA_INTERNAL_ERROR)
/* Generated */    namespace TA { namespace Lib {
/* Generated */ #elif defined( _JAVA )
/* Generated */    #include "ta_defs.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (NAMESPACE(TA_RetCode)TA_INTERNAL_ERROR)
/* Generated */ #else
/* Generated */    #include <string.h>
/* Generated */    #include <math.h>
/* Generated */    #include "ta_func.h"
/* Generated */    #include "ta_trace.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_UTILITY_H
/* Generated */    #include "ta_utility.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_MEMORY_H
/* Generated */    #include "ta_memory.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #define TA_PREFIX(x) TA_##x
/* Generated */ #define INPUT_TYPE   double
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ int Core::MACD_Lookback( int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                        int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                        int           optInSignalPeriod )  /* From 1 to 100000 */
/* Generated */ 
/* Generated */ #elif defined( _JAVA )
/* Generated */ public int MACD_Lookback( int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                         int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                         int           optInSignalPeriod )  /* From 1 to 100000 */
/* Generated */ 
/* Generated */ #else
/* Generated */ int TA_MACD_Lookback( int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                     int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                     int           optInSignalPeriod )  /* From 1 to 100000 */
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */

   /* The lookback is driven by the signal line output.
    *
    * (must also account for the initial data consume 
    *  by the slow period).
    */
   int tempInteger;

   /* Make sure slow is really slower than
    * the fast period! if not, swap...
    */
   if( optInSlowPeriod < optInFastPeriod )
   {
       /* swap */
       tempInteger       = optInSlowPeriod;
       optInSlowPeriod = optInFastPeriod;
       optInFastPeriod = tempInteger;
   }

   return   LOOKBACK_CALL(EMA)( optInSlowPeriod   )
          + LOOKBACK_CALL(EMA)( optInSignalPeriod );
}


/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_MACD - Moving Average Convergence/Divergence
 * 
 * Input  = double
 * Output = double, double, double
 * 
 * Optional Parameters
 * -------------------
 * optInFastPeriod:(From 2 to 100000)
 *    Number of period for the fast MA
 * 
 * optInSlowPeriod:(From 2 to 100000)
 *    Number of period for the slow MA
 * 
 * optInSignalPeriod:(From 1 to 100000)
 *    Smoothing for the signal line (nb of period)
 * 
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum class Core::TA_RetCode Core::MACD( int    startIdx,
/* Generated */                                         int    endIdx,
/* Generated */                                         cli::array<double>^ inReal,
/* Generated */                                         int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                                         int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                                         int           optInSignalPeriod, /* From 1 to 100000 */
/* Generated */                                         [Out]int%    outBegIdx,
/* Generated */                                         [Out]int%    outNbElement,
/* Generated */                                         cli::array<double>^  outMACD,
/* Generated */                                         cli::array<double>^  outMACDSignal,
/* Generated */                                         cli::array<double>^  outMACDHist )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public TA_RetCode MACD( int    startIdx,
/* Generated */                         int    endIdx,
/* Generated */                         double       inReal[],
/* Generated */                         int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                         int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                         int           optInSignalPeriod, /* From 1 to 100000 */
/* Generated */                         MInteger     outBegIdx,
/* Generated */                         MInteger     outNbElement,
/* Generated */                         double        outMACD[],
/* Generated */                         double        outMACDSignal[],
/* Generated */                         double        outMACDHist[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_MACD( int    startIdx,
/* Generated */                     int    endIdx,
/* Generated */                     const double inReal[],
/* Generated */                     int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                     int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                     int           optInSignalPeriod, /* From 1 to 100000 */
/* Generated */                     int          *outBegIdx,
/* Generated */                     int          *outNbElement,
/* Generated */                     double        outMACD[],
/* Generated */                     double        outMACDSignal[],
/* Generated */                     double        outMACDHist[] )
/* Generated */ #endif
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */ 
/* Generated */    /* Validate the requested output range. */
/* Generated */    if( startIdx < 0 )
/* Generated */       return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_START_INDEX;
/* Generated */    if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */       return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_END_INDEX;
/* Generated */ 
/* Generated */    /* Validate the parameters. */
/* Generated */    #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */    if( !inReal ) return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */    #endif /* !defined(_MANAGED) && !defined(_JAVA)*/
/* Generated */    /* min/max are checked for optInFastPeriod. */
/* Generated */    if( (int)optInFastPeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInFastPeriod = 12;
/* Generated */    else if( ((int)optInFastPeriod < 2) || ((int)optInFastPeriod > 100000) )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    /* min/max are checked for optInSlowPeriod. */
/* Generated */    if( (int)optInSlowPeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInSlowPeriod = 26;
/* Generated */    else if( ((int)optInSlowPeriod < 2) || ((int)optInSlowPeriod > 100000) )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    /* min/max are checked for optInSignalPeriod. */
/* Generated */    if( (int)optInSignalPeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInSignalPeriod = 9;
/* Generated */    else if( ((int)optInSignalPeriod < 1) || ((int)optInSignalPeriod > 100000) )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */    if( !outMACD )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( !outMACDSignal )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( !outMACDHist )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #endif /* !defined(_MANAGED) && !defined(_JAVA) */
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */  

   return FUNCTION_CALL(INT_MACD)( startIdx, endIdx, inReal,
                                   optInFastPeriod,
                                   optInSlowPeriod,
                                   optInSignalPeriod,
                                   outBegIdx,
                                   outNbElement,
                                   outMACD,
                                   outMACDSignal,
                                   outMACDHist );
}

#if defined( _MANAGED )
 enum class Core::TA_RetCode Core::INT_MACD( int    startIdx,
                                             int    endIdx,
											 cli::array<INPUT_TYPE>^ inReal,
                                             int    optInFastPeriod, /* From 1 to 200, 0 is fix 12 */
                                             int    optInSlowPeriod, /* From 1 to 200, 0 is fix 26 */
                                             int    optInSignalPeriod_2, /* From 1 to 200 */
                                             [Out]int% outBegIdx,
                                             [Out]int% outNbElement,
											 cli::array<double>^ outMACD,
                                             cli::array<double>^ outMACDSignal,
                                             cli::array<double>^ outMACDHist )
#elif defined( _JAVA )
TA_RetCode INT_MACD( int        startIdx,
                     int        endIdx,
                     INPUT_TYPE inReal[],
                     int        optInFastPeriod, /* From 1 to 200, 0 is fix 12 */
                     int        optInSlowPeriod, /* From 1 to 200, 0 is fix 26 */
                     int        optInSignalPeriod_2, /* From 1 to 200 */
                     MInteger   outBegIdx,
                     MInteger   outNbElement,
                     double     outMACD[],
                     double     outMACDSignal[],
                     double     outMACDHist[] )

#else
TA_RetCode TA_PREFIX(INT_MACD)( int    startIdx,
                                int    endIdx,
                                const INPUT_TYPE inReal[],
                                int    optInFastPeriod, /* From 1 to 200, 0 is fix 12 */
                                int    optInSlowPeriod, /* From 1 to 200, 0 is fix 26 */
                                int    optInSignalPeriod_2, /* From 1 to 200 */
                                int   *outBegIdx,
                                int   *outNbElement,
                                double       outMACD[],
                                double       outMACDSignal[],
                                double       outMACDHist[] )
#endif
{
   ARRAY_REF(slowEMABuffer);
   ARRAY_REF(fastEMABuffer);
   double k1, k2;
   TA_RetCode retCode;
   int tempInteger;
   VALUE_HANDLE_INT(outBegIdx1);
   VALUE_HANDLE_INT(outNbElement1);
   VALUE_HANDLE_INT(outBegIdx2);
   VALUE_HANDLE_INT(outNbElement2);
   int lookbackTotal, lookbackSignal;
   int i;

   /* !!! A lot of speed optimization could be done
    * !!! with this function. 
    * !!!
    * !!! A better approach would be to use TA_INT_EMA
    * !!! just to get the seeding values for the
    * !!! fast and slow EMA. Then process the difference
    * !!! in an allocated buffer until enough data is
    * !!! available for the first signal value.
    * !!! From that point all the processing can
    * !!! be done in a tight loop.
    * !!!
    * !!! That approach will have the following
    * !!! advantage:
    * !!!   1) One mem allocation needed instead of two.
    * !!!   2) The mem allocation size will be only the
    * !!!      signal lookback period instead of the 
    * !!!      whole range of data.
    * !!!   3) Processing will be done in a tight loop.
    * !!!      allowing to avoid a lot of memory store-load
    * !!!      operation.
    * !!!   4) The memcpy at the end will be eliminated!
    * !!!
    * !!! If only I had time....
    */

   /* Make sure slow is really slower than
    * the fast period! if not, swap...
    */
   if( optInSlowPeriod < optInFastPeriod )
   {
       /* swap */
       tempInteger       = optInSlowPeriod;
       optInSlowPeriod = optInFastPeriod;
       optInFastPeriod = tempInteger;
   }

   /* Catch special case for fix 26/12 MACD. */
   if( optInSlowPeriod != 0 )
      k1 = PER_TO_K(optInSlowPeriod);
   else
   {
      optInSlowPeriod = 26;
      k1 = (double)0.075; /* Fix 26 */
   }

   if( optInFastPeriod != 0 )
      k2 = PER_TO_K(optInFastPeriod);
   else
   {
      optInFastPeriod = 12;
      k2 = (double)0.15; /* Fix 12 */
   }

   lookbackSignal = LOOKBACK_CALL(EMA)( optInSignalPeriod_2 ); 

   /* Move up the start index if there is not
    * enough initial data.
    */
   lookbackTotal =  lookbackSignal;
   lookbackTotal += LOOKBACK_CALL(EMA)( optInSlowPeriod );

   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
      return NAMESPACE(TA_RetCode)TA_SUCCESS;
   }

   /* Allocate intermediate buffer for fast/slow EMA. */
   tempInteger = (endIdx-startIdx)+1+lookbackSignal;
   ARRAY_ALLOC( fastEMABuffer, tempInteger );
   #if !defined( _JAVA )
      if( !fastEMABuffer )
      {
         VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
         VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
         return NAMESPACE(TA_RetCode)TA_ALLOC_ERR;
      }
   #endif

   ARRAY_ALLOC( slowEMABuffer, tempInteger );
   #if !defined( _JAVA )
      if( !slowEMABuffer )
      {
         VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
         VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
         ARRAY_FREE( fastEMABuffer );
         return NAMESPACE(TA_RetCode)TA_ALLOC_ERR;
      }
   #endif

   /* Calculate the slow EMA. 
    *
    * Move back the startIdx to get enough data
    * for the signal period. That way, once the
    * signal calculation is done, all the output
    * will start at the requested 'startIdx'.
    */
   tempInteger = startIdx-lookbackSignal;
   retCode = FUNCTION_CALL(INT_EMA)( tempInteger, endIdx,
                                     inReal, optInSlowPeriod, k1,
                                     VALUE_HANDLE_OUT(outBegIdx1), VALUE_HANDLE_OUT(outNbElement1), slowEMABuffer );

   if( retCode != NAMESPACE(TA_RetCode)TA_SUCCESS )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
      ARRAY_FREE( fastEMABuffer );
      ARRAY_FREE( slowEMABuffer );
      return retCode;
   }

   /* Calculate the fast EMA. */
   retCode = FUNCTION_CALL(INT_EMA)( tempInteger, endIdx,
                                     inReal, optInFastPeriod, k2,
                                     VALUE_HANDLE_OUT(outBegIdx2), VALUE_HANDLE_OUT(outNbElement2), fastEMABuffer );

   if( retCode != NAMESPACE(TA_RetCode)TA_SUCCESS )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
      ARRAY_FREE( fastEMABuffer );
      ARRAY_FREE( slowEMABuffer );
      return retCode;
   }

   /* Parano tests. Will be removed eventually. */
   if( (VALUE_HANDLE_GET(outBegIdx1) != tempInteger) || 
       (VALUE_HANDLE_GET(outBegIdx2) != tempInteger) || 
       (VALUE_HANDLE_GET(outNbElement1) != VALUE_HANDLE_GET(outNbElement2)) ||
       (VALUE_HANDLE_GET(outNbElement1) != (endIdx-startIdx)+1+lookbackSignal) )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
      ARRAY_FREE( fastEMABuffer );
      ARRAY_FREE( slowEMABuffer );
      return TA_INTERNAL_ERROR(119);
   }

   /* Calculate (fast EMA) - (slow EMA). */
   for( i=0; i < VALUE_HANDLE_GET(outNbElement1); i++ )
      fastEMABuffer[i] = fastEMABuffer[i] - slowEMABuffer[i];


   /* Copy the result into the output for the caller. */
   ARRAY_MEMMOVE( outMACD, 0, fastEMABuffer, lookbackSignal, (endIdx-startIdx)+1 );

   /* Calculate the signal/trigger line. */
   retCode = FUNCTION_CALL_DOUBLE(INT_EMA)( 0, VALUE_HANDLE_GET(outNbElement1)-1,
                                            fastEMABuffer, optInSignalPeriod_2, PER_TO_K(optInSignalPeriod_2), 
                                            VALUE_HANDLE_OUT(outBegIdx2), VALUE_HANDLE_OUT(outNbElement2), outMACDSignal );


   ARRAY_FREE( fastEMABuffer );
   ARRAY_FREE( slowEMABuffer );

   if( retCode != NAMESPACE(TA_RetCode)TA_SUCCESS )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
      return retCode;
   }

   /* Calculate the histogram. */
   for( i=0; i < VALUE_HANDLE_GET(outNbElement2); i++ )
      outMACDHist[i] = outMACD[i]-outMACDSignal[i];


   /* All done! Indicate the output limits and return success. */
   VALUE_HANDLE_DEREF(outBegIdx)     = startIdx;
   VALUE_HANDLE_DEREF(outNbElement)  = VALUE_HANDLE_GET(outNbElement2);

   return NAMESPACE(TA_RetCode)TA_SUCCESS;
}


/**** START GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #define  USE_SINGLE_PRECISION_INPUT
/* Generated */ #if !defined( _MANAGED ) && !defined( _JAVA )
/* Generated */    #undef   TA_PREFIX
/* Generated */    #define  TA_PREFIX(x) TA_S_##x
/* Generated */ #endif
/* Generated */ #undef   INPUT_TYPE
/* Generated */ #define  INPUT_TYPE float
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum class Core::TA_RetCode Core::MACD( int    startIdx,
/* Generated */                                         int    endIdx,
/* Generated */                                         cli::array<float>^ inReal,
/* Generated */                                         int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                                         int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                                         int           optInSignalPeriod, /* From 1 to 100000 */
/* Generated */                                         [Out]int%    outBegIdx,
/* Generated */                                         [Out]int%    outNbElement,
/* Generated */                                         cli::array<double>^  outMACD,
/* Generated */                                         cli::array<double>^  outMACDSignal,
/* Generated */                                         cli::array<double>^  outMACDHist )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public TA_RetCode MACD( int    startIdx,
/* Generated */                         int    endIdx,
/* Generated */                         float        inReal[],
/* Generated */                         int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                         int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                         int           optInSignalPeriod, /* From 1 to 100000 */
/* Generated */                         MInteger     outBegIdx,
/* Generated */                         MInteger     outNbElement,
/* Generated */                         double        outMACD[],
/* Generated */                         double        outMACDSignal[],
/* Generated */                         double        outMACDHist[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_MACD( int    startIdx,
/* Generated */                       int    endIdx,
/* Generated */                       const float  inReal[],
/* Generated */                       int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                       int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                       int           optInSignalPeriod, /* From 1 to 100000 */
/* Generated */                       int          *outBegIdx,
/* Generated */                       int          *outNbElement,
/* Generated */                       double        outMACD[],
/* Generated */                       double        outMACDSignal[],
/* Generated */                       double        outMACDHist[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_START_INDEX;
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_END_INDEX;
/* Generated */     #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */     if( !inReal ) return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #endif 
/* Generated */     if( (int)optInFastPeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInFastPeriod = 12;
/* Generated */     else if( ((int)optInFastPeriod < 2) || ((int)optInFastPeriod > 100000) )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     if( (int)optInSlowPeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInSlowPeriod = 26;
/* Generated */     else if( ((int)optInSlowPeriod < 2) || ((int)optInSlowPeriod > 100000) )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     if( (int)optInSignalPeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInSignalPeriod = 9;
/* Generated */     else if( ((int)optInSignalPeriod < 1) || ((int)optInSignalPeriod > 100000) )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */     if( !outMACD )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     if( !outMACDSignal )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     if( !outMACDHist )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #endif 
/* Generated */  #endif 
/* Generated */    return FUNCTION_CALL(INT_MACD)( startIdx, endIdx, inReal,
/* Generated */                                    optInFastPeriod,
/* Generated */                                    optInSlowPeriod,
/* Generated */                                    optInSignalPeriod,
/* Generated */                                    outBegIdx,
/* Generated */                                    outNbElement,
/* Generated */                                    outMACD,
/* Generated */                                    outMACDSignal,
/* Generated */                                    outMACDHist );
/* Generated */ }
/* Generated */ #if defined( _MANAGED )
/* Generated */  enum class Core::TA_RetCode Core::INT_MACD( int    startIdx,
/* Generated */                                              int    endIdx,
/* Generated */ 											 cli::array<INPUT_TYPE>^ inReal,
/* Generated */                                              int    optInFastPeriod, 
/* Generated */                                              int    optInSlowPeriod, 
/* Generated */                                              int    optInSignalPeriod_2, 
/* Generated */                                              [Out]int% outBegIdx,
/* Generated */                                              [Out]int% outNbElement,
/* Generated */ 											 cli::array<double>^ outMACD,
/* Generated */                                              cli::array<double>^ outMACDSignal,
/* Generated */                                              cli::array<double>^ outMACDHist )
/* Generated */ #elif defined( _JAVA )
/* Generated */ TA_RetCode INT_MACD( int        startIdx,
/* Generated */                      int        endIdx,
/* Generated */                      INPUT_TYPE inReal[],
/* Generated */                      int        optInFastPeriod, 
/* Generated */                      int        optInSlowPeriod, 
/* Generated */                      int        optInSignalPeriod_2, 
/* Generated */                      MInteger   outBegIdx,
/* Generated */                      MInteger   outNbElement,
/* Generated */                      double     outMACD[],
/* Generated */                      double     outMACDSignal[],
/* Generated */                      double     outMACDHist[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_PREFIX(INT_MACD)( int    startIdx,
/* Generated */                                 int    endIdx,
/* Generated */                                 const INPUT_TYPE inReal[],
/* Generated */                                 int    optInFastPeriod, 
/* Generated */                                 int    optInSlowPeriod, 
/* Generated */                                 int    optInSignalPeriod_2, 
/* Generated */                                 int   *outBegIdx,
/* Generated */                                 int   *outNbElement,
/* Generated */                                 double       outMACD[],
/* Generated */                                 double       outMACDSignal[],
/* Generated */                                 double       outMACDHist[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */    ARRAY_REF(slowEMABuffer);
/* Generated */    ARRAY_REF(fastEMABuffer);
/* Generated */    double k1, k2;
/* Generated */    TA_RetCode retCode;
/* Generated */    int tempInteger;
/* Generated */    VALUE_HANDLE_INT(outBegIdx1);
/* Generated */    VALUE_HANDLE_INT(outNbElement1);
/* Generated */    VALUE_HANDLE_INT(outBegIdx2);
/* Generated */    VALUE_HANDLE_INT(outNbElement2);
/* Generated */    int lookbackTotal, lookbackSignal;
/* Generated */    int i;
/* Generated */    if( optInSlowPeriod < optInFastPeriod )
/* Generated */    {
/* Generated */        tempInteger       = optInSlowPeriod;
/* Generated */        optInSlowPeriod = optInFastPeriod;
/* Generated */        optInFastPeriod = tempInteger;
/* Generated */    }
/* Generated */    if( optInSlowPeriod != 0 )
/* Generated */       k1 = PER_TO_K(optInSlowPeriod);
/* Generated */    else
/* Generated */    {
/* Generated */       optInSlowPeriod = 26;
/* Generated */       k1 = (double)0.075; 
/* Generated */    }
/* Generated */    if( optInFastPeriod != 0 )
/* Generated */       k2 = PER_TO_K(optInFastPeriod);
/* Generated */    else
/* Generated */    {
/* Generated */       optInFastPeriod = 12;
/* Generated */       k2 = (double)0.15; 
/* Generated */    }
/* Generated */    lookbackSignal = LOOKBACK_CALL(EMA)( optInSignalPeriod_2 ); 
/* Generated */    lookbackTotal =  lookbackSignal;
/* Generated */    lookbackTotal += LOOKBACK_CALL(EMA)( optInSlowPeriod );
/* Generated */    if( startIdx < lookbackTotal )
/* Generated */       startIdx = lookbackTotal;
/* Generated */    if( startIdx > endIdx )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */       return NAMESPACE(TA_RetCode)TA_SUCCESS;
/* Generated */    }
/* Generated */    tempInteger = (endIdx-startIdx)+1+lookbackSignal;
/* Generated */    ARRAY_ALLOC( fastEMABuffer, tempInteger );
/* Generated */    #if !defined( _JAVA )
/* Generated */       if( !fastEMABuffer )
/* Generated */       {
/* Generated */          VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */          VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */          return NAMESPACE(TA_RetCode)TA_ALLOC_ERR;
/* Generated */       }
/* Generated */    #endif
/* Generated */    ARRAY_ALLOC( slowEMABuffer, tempInteger );
/* Generated */    #if !defined( _JAVA )
/* Generated */       if( !slowEMABuffer )
/* Generated */       {
/* Generated */          VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */          VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */          ARRAY_FREE( fastEMABuffer );
/* Generated */          return NAMESPACE(TA_RetCode)TA_ALLOC_ERR;
/* Generated */       }
/* Generated */    #endif
/* Generated */    tempInteger = startIdx-lookbackSignal;
/* Generated */    retCode = FUNCTION_CALL(INT_EMA)( tempInteger, endIdx,
/* Generated */                                      inReal, optInSlowPeriod, k1,
/* Generated */                                      VALUE_HANDLE_OUT(outBegIdx1), VALUE_HANDLE_OUT(outNbElement1), slowEMABuffer );
/* Generated */    if( retCode != NAMESPACE(TA_RetCode)TA_SUCCESS )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */       ARRAY_FREE( fastEMABuffer );
/* Generated */       ARRAY_FREE( slowEMABuffer );
/* Generated */       return retCode;
/* Generated */    }
/* Generated */    retCode = FUNCTION_CALL(INT_EMA)( tempInteger, endIdx,
/* Generated */                                      inReal, optInFastPeriod, k2,
/* Generated */                                      VALUE_HANDLE_OUT(outBegIdx2), VALUE_HANDLE_OUT(outNbElement2), fastEMABuffer );
/* Generated */    if( retCode != NAMESPACE(TA_RetCode)TA_SUCCESS )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */       ARRAY_FREE( fastEMABuffer );
/* Generated */       ARRAY_FREE( slowEMABuffer );
/* Generated */       return retCode;
/* Generated */    }
/* Generated */    if( (VALUE_HANDLE_GET(outBegIdx1) != tempInteger) || 
/* Generated */        (VALUE_HANDLE_GET(outBegIdx2) != tempInteger) || 
/* Generated */        (VALUE_HANDLE_GET(outNbElement1) != VALUE_HANDLE_GET(outNbElement2)) ||
/* Generated */        (VALUE_HANDLE_GET(outNbElement1) != (endIdx-startIdx)+1+lookbackSignal) )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */       ARRAY_FREE( fastEMABuffer );
/* Generated */       ARRAY_FREE( slowEMABuffer );
/* Generated */       return TA_INTERNAL_ERROR(119);
/* Generated */    }
/* Generated */    for( i=0; i < VALUE_HANDLE_GET(outNbElement1); i++ )
/* Generated */       fastEMABuffer[i] = fastEMABuffer[i] - slowEMABuffer[i];
/* Generated */    ARRAY_MEMMOVE( outMACD, 0, fastEMABuffer, lookbackSignal, (endIdx-startIdx)+1 );
/* Generated */    retCode = FUNCTION_CALL_DOUBLE(INT_EMA)( 0, VALUE_HANDLE_GET(outNbElement1)-1,
/* Generated */                                             fastEMABuffer, optInSignalPeriod_2, PER_TO_K(optInSignalPeriod_2), 
/* Generated */                                             VALUE_HANDLE_OUT(outBegIdx2), VALUE_HANDLE_OUT(outNbElement2), outMACDSignal );
/* Generated */    ARRAY_FREE( fastEMABuffer );
/* Generated */    ARRAY_FREE( slowEMABuffer );
/* Generated */    if( retCode != NAMESPACE(TA_RetCode)TA_SUCCESS )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */       return retCode;
/* Generated */    }
/* Generated */    for( i=0; i < VALUE_HANDLE_GET(outNbElement2); i++ )
/* Generated */       outMACDHist[i] = outMACD[i]-outMACDSignal[i];
/* Generated */    VALUE_HANDLE_DEREF(outBegIdx)     = startIdx;
/* Generated */    VALUE_HANDLE_DEREF(outNbElement)  = VALUE_HANDLE_GET(outNbElement2);
/* Generated */    return NAMESPACE(TA_RetCode)TA_SUCCESS;
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }} // Close namespace TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

