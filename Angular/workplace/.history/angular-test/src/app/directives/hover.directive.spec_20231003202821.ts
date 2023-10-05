import { HoverDirective } from './hover.directive';

describe('HoverDirective', () => {
  it('should create an instance', () => {
    const directive = new HoverDirective(private elementRef: ElementRef);
    expect(directive).toBeTruthy();
  });
});
