#ifndef EMBIND_CLASSES_COL_ACCESS_HPP
#define EMBIND_CLASSES_COL_ACCESS_HPP

#include <emscripten/bind.h>
using namespace emscripten;

#include <string>
#include <armadillo>

template<typename ColType>
struct ColAccess {
      static val get(
          const ColType& self,
          arma::uword idx
      ) {
          if (idx < self.n_elem) {
              return val(self(idx));
          } else {
              return val::undefined();
          }
      }

      static bool set(
          ColType& self,
          arma::uword idx,
          const typename ColType::elem_type& value
      ) {
          if (idx >= self.n_elem)
            return false;

          self(idx) = value;
          return true;
      }

      static bool set_size(
        ColType& self,
        arma::uword n_elem
      ) {
          self.set_size(n_elem);
          return true;
      }
};

#endif // EMBIND_CLASSES_COL_ACCESS_HPP
