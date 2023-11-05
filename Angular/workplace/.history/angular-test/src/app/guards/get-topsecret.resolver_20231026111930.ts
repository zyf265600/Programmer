import { Injectable } from '@angular/core';
import { router, Resolve,  } from '@angular/router';

export const getTopsecretResolver: ResolveFn<boolean> = (route, state) => {
  return true;
};
