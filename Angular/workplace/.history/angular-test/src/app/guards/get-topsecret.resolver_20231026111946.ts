import { Injectable } from '@angular/core';
import { Router, Resolve} from '@angular/router';

export const getTopsecretResolver: ResolveFn<boolean> = (route, state) => {
  return true;
};
