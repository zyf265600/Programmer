import { Injectable } from '@angular/core';
import { router, Resolve, Route } from '@angular/router';

export const getTopsecretResolver: ResolveFn<boolean> = (route, state) => {
  return true;
};
