import { Injectable } from '@angular/core';
import { Injectable } from '@angular/router';

export const getTopsecretResolver: ResolveFn<boolean> = (route, state) => {
  return true;
};
