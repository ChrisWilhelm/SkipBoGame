// Chris Wilhelm cwilhel8
// Derek Dang ddang8
// Udochukwu Nwosu unwosu6

#include <vector>
#include "BuildPile.h"
#include "FaceUpPile.h"
#include "Pile.h"
#include "Card.h"

bool BuildPile::isValid(Card play) {
  if((int)pile.size() + 1  == play.getValue() || 0 == play.getValue()) {
    return true;
  }
  else {
    return false;
  }
}
