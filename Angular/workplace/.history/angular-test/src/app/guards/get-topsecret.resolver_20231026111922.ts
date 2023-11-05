import { Injectable } from '@angular/core';
import { router } from '@angular/router';

export const getTopsecretResolver: ResolveFn<boolean> = (route, state) => {
  return true;
};
