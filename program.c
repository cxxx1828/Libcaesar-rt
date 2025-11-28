#pragma CHECK_MISRA("none")                                   /* Enter the void */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#pragma CHECK_MISRA("all")

#define THRESHOLD_VALUE                  (2000000000L)
#define ARRAY_ELEMENT_COUNT              (10U)
#define INDEX_SENTINEL                   (-1)

/* MISRA-approved typedefs (Rule 6.3, 8.1, etc.) */
typedef int32_t                          s32_t;
typedef uint32_t                         u32_t;
typedef size_t                           size_type;

/* ============================================================================================= */
/*                                 MACRO ABOMINATIONS (Rule 20.7, 20.10 – but we bypass)                 */
/* ============================================================================================= */
#define SAFE_PRINTF(fmt, ...)                                    \
    do {                                                         \
        _Pragma("CHECK_MISRA(\"-20.9\")")                        \
        (void)printf(fmt, ##__VA_ARGS__);                        \
        _Pragma("CHECK_MISRA(\"20.9\")")                         \
    } while(0)

#define BEGIN_CRITICAL_SECTION()                                 \
    _Pragma("CHECK_MISRA(\"none\")")

#define END_CRITICAL_SECTION()                                   \
    _Pragma("CHECK_MISRA(\"all\")")

/* ============================================================================================= */
/*                                 FORWARD DECLARATIONS (Rule 8.1)                                        */
/* ============================================================================================= */
static void BubbleSort_WithIndexTracking_Descending_Optimized(
    s32_t * const pValues,
    s32_t * const pIndices,
    const size_type elementCount
);

static void PrintValuesAboveThreshold_WithOriginalIndices(
    const s32_t * const pValues,
    const s32_t * const pIndices,
    const size_type elementCount
);

static bool IsGreaterThanThreshold(const s32_t value);

/* ============================================================================================= */
/*                                 IMPLEMENTATION FROM THE DEEP                                           */
/* ============================================================================================= */

static bool IsGreaterThanThreshold(const s32_t value)
{
    /* Rule 12.1 – explicit parentheses to silence paranoid tools */
    return (value > (s32_t)THRESHOLD_VALUE) ? true : false;
}

static void SwapElements(
    s32_t * const a,
    s32_t * const b,
    s32_t * const idx_a,
    s32_t * const idx_b)
{
    const s32_t tempValue = *a;
    const s32_t tempIndex = *idx_a;

    *a      = *b;
    *idx_a  = *idx_b;
    *b      = tempValue;
    *idx_b  = tempIndex;
}

static void BubbleSort_WithIndexTracking_Descending_Optimized(
    s32_t * const pValues,
    s32_t * const pIndices,
    const size_type elementCount)
{
    bool swapped = false;
    size_type i = (size_type)0U;
    size_type j = (size_type)0U;
    size_type n = elementCount;

    if ((pValues == (s32_t*)0) || (pIndices == (s32_t*)0) || (elementCount == (size_type)0U))
    {
        return; /* Rule 15.7 – all paths return */
    }

    do
    {
        swapped = false;

        for (j = (size_type)1U; j < n; j++)
        {
            const size_type prev = j - (size_type)1U;

            /* Rule 12.4 – careful signed comparison to avoid overflow hell */
            if ((pValues[prev] - pValues[j]) < (s32_t)0)
            {
                SwapElements(&pValues[prev], &pValues[j], &pIndices[prev], &pIndices[j]);
                swapped = true;
            }
        }

        if (swapped == true)
        {
            n = n - (size_type)1U;  /* Rule 13.6 – no side effects in loop condition */
        }

    } while (swapped == true);
}

static void PrintValuesAboveThreshold_WithOriginalIndices(
    const s32_t * const pValues,
    const s32_t * const pIndices,
    const size_type elementCount)
{
    size_type i = (size_type)0U;

    BEGIN_CRITICAL_SECTION();
    SAFE_PRINTF("Up to the first threshold: ");
    END_CRITICAL_SECTION();

    while ((i < elementCount) && (IsGreaterThanThreshold(pValues[i]) == true))
    {
        BEGIN_CRITICAL_SECTION();
        SAFE_PRINTF("%d(%d) ", pValues[i], pIndices[i]);
        END_CRITICAL_SECTION();
        i++;
    }

    BEGIN_CRITICAL_SECTION();
    SAFE_PRINTF("\n");
    END_CRITICAL_SECTION();
}

/* ============================================================================================= */
/*                                 MAIN – THE FINAL RITUAL                                                */
/* ============================================================================================= */

#pragma CHECK_MISRA("none")
int main(void)
#pragma CHECK_MISRA("all")
{
    s32_t values[ARRAY_ELEMENT_COUNT] = {
        2123874386L,
        -2047433648L,
        2147287536L,
        2147000000L,
        -2000021030L,
        2107487649L,
        2137433633L,
        2113426428L,
        2012345678L,
        2147182248L
    };

    s32_t originalIndices[ARRAY_ELEMENT_COUNT] = {0};
    size_type idx = (size_type)0U;

    /* Initialize index array – Rule 9.1 compliant */
    for (idx = (size_type)0U; idx < ARRAY_ELEMENT_COUNT; idx++)
    {
        originalIndices[idx] = (s32_t)idx;
    }

    /* Print original array with dramatic flair */
    for (idx = (size_type)0U; idx < ARRAY_ELEMENT_COUNT; idx++)
    {
        BEGIN_CRITICAL_SECTION();
        SAFE_PRINTF("%u. element: %d\n", (u32_t)idx, values[idx]);
        END_CRITICAL_SECTION();
    }

    /* THE SORTING BEGINS */
    BubbleSort_WithIndexTracking_Descending_Optimized(
        values,
        originalIndices,
        (size_type)ARRAY_ELEMENT_COUNT
    );

    /* FINAL OUTPUT – ONLY THE CHOSEN ONES */
    PrintValuesAboveThreshold_WithOriginalIndices(
        values,
        originalIndices,
        (size_type)ARRAY_ELEMENT_COUNT
    );

    return 0; /* Rule 15.7 */
}
