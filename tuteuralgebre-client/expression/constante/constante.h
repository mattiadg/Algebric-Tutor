#ifndef CONSTANTE_H
#define CONSTANTE_H

#include "../expression.h"

/**
 * \brief Constante represents a literal double value. Its eval() returns the constant value.
 * We use a class to store a double only to be coherent with th Composite Pattern.
 */
class Constante : public Expression
{
    public:
		/**
		 * Constructor.
		 *
		 * @param _value The double value to store
		 */
        Constante(const double _value);
        /**
         * Destructor.
         */
        virtual ~Constante();
        /**
         * @return The double value stored.
         */
        virtual double eval() const;
    private:
        const double value;
};

#endif // CONSTANTE_H
