import { ResolveFn } from '@angular/router';

export const getTopsecretResolver: ResolveFn<boolean> = (route, state) => {
  return true;
};
