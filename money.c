#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include "dollar.h"
#include "franc.h"
#include "money.h"
#include "money_private.h"


Money *
franc( unsigned int amount ) {
  return ( Money * ) create_franc( amount, CHF );
}


Money *
dollar( unsigned int amount ) {
  return ( Money * ) create_dollar( amount, USD );
}


Money *
create_money( unsigned int amount, Currency currency ) {
  MoneyPrivate *money = malloc( sizeof( MoneyPrivate ) );
  money->amount = amount;
  money->currency = currency;
  return ( Money * ) money;
}


Money *
multiply( Money * money, Currency currency, int multiplier ){
  return create_money( ( ( MoneyPrivate * ) money )->amount * multiplier, currency);
}


Currency
currency_of( const Money *money ) {
  return ( ( MoneyPrivate * ) money )->currency;
}


bool
equal( const void *money, Currency currency, const void *other, Currency other_currency ) {
  return ( ( ( MoneyPrivate * ) money )->amount == ( ( MoneyPrivate * ) other )->amount ) 
    && ( currency == other_currency );
}
