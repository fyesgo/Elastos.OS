
#ifndef __ELASTOS_DROID_INTERNAL_TELEPHONY_CSMS7BITENCODINGTRANSLATOR_H__
#define __ELASTOS_DROID_INTERNAL_TELEPHONY_CSMS7BITENCODINGTRANSLATOR_H__

#include "_Elastos_Droid_Internal_Telephony_CSms7BitEncodingTranslator.h"

#include "_Elastos.Droid.Internal.h"
#include "elastos/core/Singleton.h"
#include "elastos/droid/utility/SparseInt32Array.h"

using Elastos::Core::Singleton;
using Elastos::Core::ICharSequence;

using Elastos::Droid::Utility::ISparseInt32Array;

namespace Elastos {
namespace Droid {
namespace Internal {
namespace Telephony {

CarClass(CSms7BitEncodingTranslator)
    , public Singleton
    , public ISms7BitEncodingTranslator
{
public:
    CAR_SINGLETON_DECL()

    CAR_INTERFACE_DECL()

    /**
     * Translates each message character that is not supported by GSM 7bit
     * alphabet into a supported one
     *
     * @param message
     *            message to be translated
     * @param throwsException
     *            if TRUE and some error occurs during translation, an exception
     *            is thrown; otherwise a NULL String is returned
     * @return translated message or NULL if some error occur
     */
    CARAPI Translate(ICharSequence* message, String *result);


protected:
    Sms7BitEncodingTranslator();

private:
    /**
     * Translates a single character into its corresponding acceptable one, if
     * needed, based on GSM 7-bit alphabet
     *
     * @param c
     *            character to be translated
     * @return original character, if it's present on GSM 7-bit alphabet; a
     *         corresponding character, based on the translation table or white
     *         space, if no mapping is found in the translation table for such
     *         character
     */
    static CARAPI_(Char32) TranslateIfNeeded(
        /* [in] */ Char32 c);

    static CARAPI_(Boolean) NoTranslationNeeded(
        /* [in] */ Char32 c);

    static CARAPI_(Boolean) UseCdmaFormatForMoSms();
    /**
     * Load the whole translation table file from the framework resource
     * encoded in XML.
     */
    static CARAPI_(void) Load7BitTranslationTableFromXml();

private:
    static const String TAG;
    static const Boolean DBG;
    static Boolean mIs7BitTranslationTableLoaded;
    static AutoPtr<ISparseInt32Array> mTranslationTable;
    static AutoPtr<ISparseInt32Array> mTranslationTableCommon;
    static AutoPtr<ISparseInt32Array> mTranslationTableGSM;
    static AutoPtr<ISparseInt32Array> mTranslationTableCDMA;

    // Parser variables
    static const String XML_START_TAG;
    static const String XML_TRANSLATION_TYPE_TAG;
    static const String XML_CHARACTOR_TAG;
    static const String XML_FROM_TAG;
    static const String XML_TO_TAG;
};

} // namespace Telephony
} // namespace Internal
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_INTERNAL_TELEPHONY_CSMS7BITENCODINGTRANSLATOR_H__