import { Injectable } from '@angular/core';
import { Router, Resolve, Route } from '@angular/router';

export const getTopsecretResolver: ResolveFn<boolean> = (route, state) => {
  return true;
};
